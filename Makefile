NAME = push_swap
CC = clang
FLAGS = -Wall -Werror -Wextra

SRCS = main.c instruction.c node.c stack.c algorithm.c

all: $(NAME)

$(NAME):
	$(CC) -Linc/libft/ft_printf/libftprintf.a $(SRCS) -Iinc/libft -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
