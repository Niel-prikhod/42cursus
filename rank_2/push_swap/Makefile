NAME = push_swap
SOURCES = push_swap.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = push_swap.h 

LIBFT_DIR = /libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wextra -Wall -Werror 

all: $(LIBFT) $(NAME)
$(NAME): $(OBJECTS)
	@$(CC) $(CFLAGS) -o $@ $^
$(LIBFT):
	@make -C $(LIBFT_DIR)
%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@rm -f $(OBJECTS)
	@make -C $(LIBFT_DIR) clean
fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
re: fclean all
