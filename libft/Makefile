NAME = libft.a

SOURCES = ft_isgroup.c \
	ft_malloc_group.c \
	ft_mem_group.c \
	ft_put_group.c \
	ft_split_group.c \
	ft_str_adv.c \
	ft_str_basic.c \
	ft_str_finder.c \
	ft_str_utils.c \
	ft_printf.c \
	get_next_line.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I $(CUR_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
