NAME= push_swap

CFILS= main.c ft_atoi.c parse.c ft_isdigit.c ft_putstr_fd.c\
			ft_stack.c ft_strlen.c ft_split.c ft_lst_util.c  test.c


CFLAGS= -Wall -Wextra -Werror

$(NAME): $(CFILS)
	cc $(CFLAGS) $(CFILS) -o $(NAME)

all: $(NAME)


clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)


re:	clean fclean	