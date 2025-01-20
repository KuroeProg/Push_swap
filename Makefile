NAME = push_swap
CC = clang
FLAGS = -Wall -Werror -Wextra

SRCS = main.c instruction.c node.c stack.c algorithm.c

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -g -Iinc/libft -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all
