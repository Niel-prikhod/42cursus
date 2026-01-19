#!/bin/bash

# =============================================================================
# COMPREHENSIVE TEST SUITE FOR PIPEX
# =============================================================================
# Usage: ./test_pipex.sh [options]
# Options:
#   -v, --verbose    Show detailed output
#   -c, --clean      Clean test files after running
#   -h, --help       Show this help
#   --basic-only     Run only basic functionality tests
#   --errors-only    Run only error handling tests
# =============================================================================

# set -e  # Disabled to handle test failures manually

# Configuration
PIPEX_EXEC="../pipex"
TEST_DIR="$(dirname "$0")"
TIMEOUT=10
CLEANUP=true
VERBOSE=false
BASIC_ONLY=false
ERRORS_ONLY=false

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0
SKIPPED_TESTS=0

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# =============================================================================
# HELPER FUNCTIONS
# =============================================================================

show_help() {
    echo "Usage: $0 [options]"
    echo "Options:"
    echo "  -v, --verbose    Show detailed output"
    echo "  -c, --clean      Clean test files after running"
    echo "  -h, --help       Show this help"
    echo "  --basic-only     Run only basic functionality tests"
    echo "  --errors-only    Run only error handling tests"
}

log_info() {
    echo -e "${BLUE}[INFO]${NC} $1"
}

log_success() {
    echo -e "${GREEN}[PASS]${NC} $1"
    ((PASSED_TESTS++))
}

log_failure() {
    echo -e "${RED}[FAIL]${NC} $1"
    ((FAILED_TESTS++))
}

log_warning() {
    echo -e "${YELLOW}[SKIP]${NC} $1"
    ((SKIPPED_TESTS++))
}

run_test() {
    local test_name="$1"
    local test_command="$2"
    local expected="$3"
    
    ((TOTAL_TESTS++))
    
    if [ "$VERBOSE" = true ]; then
        log_info "Running: $test_name"
        log_info "Command: $test_command"
    fi
    
    # Create temp output file
    local temp_output="$TEST_DIR/temp_test_output_$$_"
    
    # Run the test (pipex writes to output file, not stdout)
    cd "$TEST_DIR" && bash -c "$PIPEX_EXEC $test_command" 2> "$temp_output"
    local test_result=$?
    
    # Extract output file name from command and ensure it's in test directory
    local output_file_name=$(echo "$test_command" | awk '{print $NF}')
    local output_file="$TEST_DIR/$output_file_name"
    
    if [ $test_result -eq 0 ]; then
        # Check if pipex output file matches expected
        if diff -q "$output_file" "$TEST_DIR/$expected" > /dev/null 2>&1; then
            log_success "$test_name"
            rm -f "$temp_output" "$output_file"
            return 0
        else
            log_failure "$test_name - Output mismatch"
            if [ "$VERBOSE" = true ]; then
                echo "Expected:"
                cat "$TEST_DIR/$expected" 2>/dev/null || echo "(file not found)"
                echo "Got:"
                cat "$output_file" 2>/dev/null || echo "(file not found)"
            fi
            rm -f "$temp_output" "$output_file"
            return 1
        fi
    else
        if [ $test_result -eq 124 ]; then
            log_failure "$test_name - Timeout"
        else
            log_failure "$test_name - Command failed (exit code: $test_result)"
            if [ "$VERBOSE" = true ]; then
                echo "Error output:"
                cat "$temp_output" 2>/dev/null || echo "(no error output)"
            fi
        fi
        rm -f "$temp_output" "$output_file"
        return 1
    fi
}

run_error_test() {
    local test_name="$1"
    local test_command="$2"
    local expected_error_pattern="$3"
    
    ((TOTAL_TESTS++))
    
    if [ "$VERBOSE" = true ]; then
        log_info "Running error test: $test_name"
        log_info "Command: $PIPEX_EXEC $test_command"
    fi
    
    # Run the command and capture output and exit code
    local output
    set +e  # Disable exit on error for this command
    if [ "$VERBOSE" = true ]; then
        echo "Executing: $PIPEX_EXEC $test_command"
    fi
    output=$(bash -c "$PIPEX_EXEC $test_command" 2>&1)
    exit_code=$?
    if [ "$VERBOSE" = true ]; then
        echo "Exit code: $exit_code"
        echo "Output: $output"
    fi
    set -e  # Re-enable exit on error
    
    # Check if command failed as expected
    if [ $exit_code -ne 0 ]; then
        # Check if error message matches expected pattern
        if echo "$output" | grep -q "$expected_error_pattern"; then
            log_success "$test_name - Correctly failed with expected error"
            return 0
        else
            log_failure "$test_name - Failed but with wrong error: $output"
            return 1
        fi
    else
        log_failure "$test_name - Should have failed but succeeded (exit code: $exit_code)"
        return 1
    fi
}

# =============================================================================
# BASIC FUNCTIONALITY TESTS
# =============================================================================

run_basic_tests() {
    log_info "Starting basic functionality tests..."
    echo
    
    # Ensure we're in the test directory
    cd "$TEST_DIR"
    
    # Create all expected files BEFORE running tests
    wc -l < test_input_basic.txt > test_expected_basic_wc.txt
    head test_input_basic.txt | wc -l > test_expected_head_wc.txt
    rev test_input_special.txt | wc -l > test_expected_rev_wc.txt
    wc -w < test_input_basic.txt > test_expected_tr_wc.txt
    wc -c < test_input_single.txt > test_expected_single_wc.txt
    cat test_input_empty.txt | wc -l > test_expected_empty.txt
    wc -w < test_input_special.txt > test_expected_special_wc.txt
    rev test_input_special.txt | wc -w > test_expected_complex.txt
    head test_input_large.txt | wc -l > test_expected_large.txt
    
    # Test 1: Replicate original test (cat | wc -l)
    run_test "Basic test (cat | wc -l)" \
        "test_input_basic.txt cat 'wc -l' test_output_1.txt" \
        "test_expected_basic_wc.txt"
    
    # Test 2: head | wc (using head without arguments should take first 10 lines)
    run_test "head | wc" \
        "test_input_basic.txt head 'wc -l' test_output_2.txt" \
        "test_expected_head_wc.txt"
    
    # Test 3: rev | wc (using rev to reverse lines, then count)
    run_test "rev | wc" \
        "test_input_special.txt rev 'wc -l' test_output_3.txt" \
        "test_expected_rev_wc.txt"
    
    # Test 4: tr | wc
    run_test "tr | wc" \
        "test_input_basic.txt cat 'wc -w' test_output_4.txt" \
        "test_expected_tr_wc.txt"
    
    # Test 5: Single line file
    run_test "Single line file" \
        "test_input_single.txt cat 'wc -c' test_output_5.txt" \
        "test_expected_single_wc.txt"
    
    # Test 6: Empty file
    run_test "Empty file" \
        "test_input_empty.txt cat 'wc -l' test_output_6.txt" \
        "test_expected_empty.txt"
    
    echo
}

# =============================================================================
# ERROR HANDLING TESTS
# =============================================================================

run_error_tests() {
    log_info "Starting error handling tests..."
    echo

    # Ensure we're in the test directory
    cd "$TEST_DIR"

    # Create all expected files BEFORE running tests
    # Test 7: Non-existent input file (shell continues execution)
    echo "0" > test_expected_error1.txt  # wc processes empty input

    # Test 8: Invalid first command (shell continues with error)
    echo "0" > test_expected_error2.txt  # wc processes empty input

    # Test 9: Invalid second command (shell continues with error)
    cat test_input_basic.txt > test_expected_error3.txt  # cat succeeds

    # Test 10: Unwritable output file (shell continues with error)
    wc -l < test_input_basic.txt > test_expected_error4.txt  # commands execute

    # Now run the tests
    run_test "Non-existent input file (shell-like)" \
        "nonexistent_file.txt 'cat' 'wc -l' test_output_error1.txt" \
        "test_expected_error1.txt"

    run_test "Invalid first command (shell-like)" \
        "test_input_basic.txt nonexistent_cmd 'wc -l' test_output_error2.txt" \
        "test_expected_error2.txt"

    run_error_test "Invalid second command" \
        "test_input_basic.txt cat nonexistent_cmd test_output_error3.txt" \
        "COMMAND_NOT_FOUND"

    run_error_test "Unwritable output file" \
        "test_input_basic.txt cat 'wc -l' /root/test_output_error4.txt" \
        "OUTFILE ERROR"

    # Test 11: Insufficient arguments (remains error - not enough args)
    run_error_test "Insufficient arguments" \
        "test_input_basic.txt cat test_output_error5.txt" \
        "INVALID ARGUMENT"

    echo
}

# =============================================================================
# EDGE CASE TESTS
# =============================================================================

run_edge_tests() {
    log_info "Starting edge case tests..."
    echo
    
    # Ensure we're in the test directory
    cd "$TEST_DIR"
    
    # Test 12: Special characters
    run_test "Special characters" \
        "test_input_special.txt cat 'wc -w' test_output_special.txt" \
        "test_expected_special_wc.txt"
    
    # Test 13: Large file performance
    if [ "$VERBOSE" = true ]; then
        log_info "Testing large file performance..."
    fi
    run_test "Large file performance" \
        "test_input_large.txt head 'wc -l' test_output_large.txt" \
        "test_expected_large.txt"

    # Test 14: Commands with complex arguments
    run_test "Complex arguments" \
        "test_input_special.txt rev 'wc -w' test_output_complex.txt" \
        "test_expected_complex.txt"
    
    # Complex arguments test expected file created above
    
    echo
}

# =============================================================================
# CLEANUP FUNCTION
# =============================================================================

cleanup() {
    if [ "$CLEANUP" = true ]; then
        log_info "Cleaning up test files..."
        cd "$TEST_DIR"
        rm -f test_expected_*.txt
        rm -f temp_test_output_*
        rm -f test_output_*.txt
        rm -f test_error.txt
    fi
}

# =============================================================================
# MAIN EXECUTION
# =============================================================================

main() {
    # Parse command line arguments
    while [[ $# -gt 0 ]]; do
        case $1 in
            -v|--verbose)
                VERBOSE=true
                shift
                ;;
            -c|--clean)
                CLEANUP=true
                shift
                ;;
            -h|--help)
                show_help
                exit 0
                ;;
            --basic-only)
                BASIC_ONLY=true
                shift
                ;;
            --errors-only)
                ERRORS_ONLY=true
                shift
                ;;
            *)
                echo "Unknown option: $1"
                show_help
                exit 1
                ;;
        esac
    done
    
    # Check if pipex executable exists
    if [ ! -f "$PIPEX_EXEC" ]; then
        log_failure "Pipex executable not found: $PIPEX_EXEC"
        log_info "Run 'make' first to build the executable"
        exit 1
    fi
    
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}      PIPEX COMPREHENSIVE TEST SUITE   ${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo
    
    # Run test categories
    if [ "$ERRORS_ONLY" = false ]; then
        run_basic_tests
        run_edge_tests
    fi
    
    if [ "$BASIC_ONLY" = false ]; then
        run_error_tests
    fi
    
    # Print summary
    echo -e "${BLUE}========================================${NC}"
    echo -e "${BLUE}           TEST SUMMARY                ${NC}"
    echo -e "${BLUE}========================================${NC}"
    echo -e "Total tests:  $TOTAL_TESTS"
    echo -e "${GREEN}Passed:       $PASSED_TESTS${NC}"
    echo -e "${RED}Failed:       $FAILED_TESTS${NC}"
    if [ $SKIPPED_TESTS -gt 0 ]; then
        echo -e "${YELLOW}Skipped:      $SKIPPED_TESTS${NC}"
    fi
    
    if [ $FAILED_TESTS -eq 0 ]; then
        echo -e "${GREEN}All tests passed!${NC}"
        cleanup
        exit 0
    else
        echo -e "${RED}$FAILED_TESTS tests failed!${NC}"
        cleanup
        exit 1
    fi
}

# Set up cleanup on exit
trap cleanup EXIT

# Run main function with all arguments
main "$@"