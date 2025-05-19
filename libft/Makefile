NAME = libft.a

SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

OBJECTS = $(SOURCES:.c=.o)

HEADERS = includes/libft.h

CFLAGS += -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	cc $(CFLAGS) -I $(CUR_DIR)/includes -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
