NAME = libft.a

SOURCES = sources/ft_isalpha.c \
		  sources/ft_isdigit.c \
		  sources/ft_isalnum.c \
		  sources/ft_isascii.c \
		  sources/ft_isprint.c \
		  sources/ft_strlen.c \
		  sources/ft_memset.c \
		  sources/ft_bzero.c \
		  sources/ft_memcpy.c \
		  sources/ft_memmove.c \
		  sources/ft_strlcpy.c \
		  sources/ft_strlcat.c \
		  sources/ft_toupper.c \
		  sources/ft_tolower.c \
		  sources/ft_strchr.c \
		  sources/ft_strrchr.c \
		#   sources/ft_strncmp.c \
		#   sources/ft_memchr.c \
		#   sources/ft_memcmp.c \
		#   sources/ft_strnstr.c \
		#   sources/ft_atoi.c \
		#   sources/ft_calloc.c \
		#   sources/ft_strdup.c


OBJECTS = $(SOURCES:.c=.o)

HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

all: $(NAME) clean

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	cc $(CFLAGS) -I $(CUR_DIR) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
