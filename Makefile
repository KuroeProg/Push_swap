NAME = push_swap
CC = clang
FLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = inc/libft
PRINTF_DIR = inc/libft/ft_printf

SRCS = main.c instruction.c node.c stack.c algorithm.c parsing.c utils/utils.c utils/utils2.c error.c ft_isdigit.c ft_split.c
OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -Iutils -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

.PHONY: all clean fclean re
