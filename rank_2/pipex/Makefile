CC = gcc
LIBFT = ./libft
CFLAGS = -Wextra -Wall -Werror -O3 -g3 -I. -I$(LIBFT)

NAME = pipex

SOURCES = pipex_main.c pipex_execution.c pipex_utils.c

BUILD = build
OBJECTS = $(addprefix $(BUILD)/, $(SOURCES:.c=.o))
HEADERS = pipex.h $(LIBFT)/libft.h

all: $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/%.o: %.c $(HEADERS) | $(BUILD)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(BUILD)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

test: re
	./pipex in.txt cat 'wc -l' out.txt
	cat out.txt

# Comprehensive test suite targets
test-all: re
	@cd tests && ./test_pipex.sh

test-basic: re
	@cd tests && ./test_pipex.sh --basic-only

test-errors: re
	@cd tests && ./test_pipex.sh --errors-only

test-verbose: re
	@cd tests && ./test_pipex.sh -v

test-clean: re
	@cd tests && ./test_pipex.sh -c

.PHONY: all clean fclean re test test-all test-basic test-errors test-verbose test-clean

