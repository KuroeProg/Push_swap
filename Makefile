NAME = push_swap
CC = clang
FLAGS = -Wall -Werror -Wextra -g

LIBFT_DIR = inc/libft
PRINTF_DIR = inc/libft/ft_printf

SRCS = main.c instruction.c node.c stack.c algorithm.c parsing.c \
	utils/utils.c utils/utils2.c error.c \
	little_size.c little_sizebis.c sort_five.c

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
PRINTF = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf

$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(FLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -Iutils -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean all