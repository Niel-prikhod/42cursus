CC = gcc
LIBFT = ./libft
CFLAGS = -Wextra -Wall -Werror -O3 -g3 -I. -I$(LIBFT)

NAME = push_swap

SOURCES = push_swap.c pb_utils.c

BUILD = build
OBJECTS = $(addprefix $(BUILD)/, $(SOURCES:.c=.o))
HEADERS = push_swap.h $(LIBFT)/libft.h

all: $(NAME)

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/%.o: %.c $(HEADERS) | $(BUILD)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	@$(CC) $(OBJECTS) $(LIBFT)/libft.a -o $(NAME) $(LDFLAGS)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)

clean:
	@rm -rf $(BUILD)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re

