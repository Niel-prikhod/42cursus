NAME = libftprintf.a

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = ft_printf.c utils.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = ft_printf.h \
		  libft/libft.h

CUR_DIR = $(shell pwd)

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT_DIR) -I .

all: $(LIBFT) $(NAME)
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJECTS) $(LIBFT)
	ar rcs $(NAME) $(OBJECTS) $(LIBFT)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(CUR_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
