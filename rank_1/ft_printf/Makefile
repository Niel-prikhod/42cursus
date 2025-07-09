NAME = libftprintf.a

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = ft_printf.c utils.c

OBJECTS = $(SOURCES:.c=.o)

CUR_DIR = $(shell pwd)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(LIBFT) $(NAME)
$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS) libft/*.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -O
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
.PHONY: all bonus clean fclean re
