NAME = push_swap
CC = clang
FLAGS = -Wall -Werror -Wextra

SRCS = main.c

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

re: fclean all