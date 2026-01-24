*This project has been created as part of the 42 curriculum by dprikhod.*

# Pipex

## Description
Pipex is a project that aims to deepen the understanding of Unix mechanisms, specifically pipes and redirections. The goal is to develop a program that mimics the behavior of the shell's pipe command.

The program handles the following execution:
`./pipex infile "cmd1" "cmd2" outfile`

Which is equivalent to the shell command:
`< infile cmd1 | cmd2 > outfile`

### Features
- Redirection of standard input and output.
- Inter-process communication using pipes.
- Execution of shell commands with arguments.
- Comprehensive error handling and propagation.
- Multi-process management with `fork`, `pipe`, `waitpid`, and `execve`.

## Instructions

### Compilation
The project comes with a Makefile that supports the following rules:
- `make`: Compiles the `pipex` executable.
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Rebuilds the project.

### Execution
Run the program using the following syntax:
```bash
./pipex <input_file> <command_1> <command_2> <output_file>
```

Example:
```bash
./pipex infile "ls -l" "wc -l" outfile
```

### Testing
A comprehensive test suite is available in the `tests/` directory. You can run it using:
- `make test`: Runs a basic functionality test.
- `make test-all`: Runs all available tests.
- `make test-basic`: Runs basic functionality tests.
- `make test-errors`: Runs error handling tests.
- `make test-verbose`: Runs tests with detailed output.

## Resources

### Tutrorials
- [UNIX processes in C by CodeVault](https://youtube.com/playlist?list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&si=EpsCgU6IVUTmwyWF)
- [git-book guide by Simon Aeby (saeby) & Laura Fabbiano (lfabbian) from 42 in Luasanne](https://42-cursus.gitbook.io/guide/2-rank-02/pipex)
- linux user manual

### AI Usage
Different models of Grok and opencode's Zen models were used.
AI was utilized in this project for the following tasks:
- **Test Suite Development**: Designing and implementing the comprehensive Bash test script located in `tests/`.
- **Debugging**: Analyzing pipe deadlocks, race conditions, and file descriptor management issues.
- **Code Optimization**: Refactoring functions for better readability and compliance with 42 school standards (Norminette).
- **Error Handling Analysis**: Investigating `errno` behavior and improving error message routing to `stderr`.
- **Documentation**: Drafting this README and other technical guides.
