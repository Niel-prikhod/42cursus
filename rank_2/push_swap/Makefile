NAME = push_swap
SOURCES = push_swap.c
OBJECTS = $(SOURCES:.c=.o)
HEADERS = push_swap.h 

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wextra -Wall -Werror 

all: $(LIBFT) $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) LIBFT_DIR/*.o
%.o: %.c
	cc $(CFLAGS) -c $< -o $@ -O
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
re: fclean all
