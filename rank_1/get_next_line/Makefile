NAME = get_next_line.a

SOURCES = get_next_line.c get_next_line_utils.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_SOURCES = get_next_line_bonus.c get_next_line_utils_bonus.c

BONUS_OBJECTS = $(BONUS_SOURCES:.c=.o)

# HEADERS = get_next_line.h

# BONUS_HEADERS = get_next_line_bonus.h

CFLAGS = -Wall -Wextra -Werror

CUR_DIR = $(shell pwd)

CC = cc

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: %.c 
	$(CC) $(CFLAGS) -I $(CUR_DIR) -c $< -o $@

bonus: $(BONUS_OBJECTS)
	ar rc $(NAME) $(BONUS_OBJECTS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

