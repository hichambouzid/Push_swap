NAME= push_swap

CFILS= main.c libft_cursus/ft_atoi.c parse.c libft_cursus/ft_isdigit.c libft_cursus/ft_putstr_fd.c\
				libft_cursus/ft_strlen.c libft_cursus/ft_split.c


CFLAGS= -Wall -Wextra -Werror

$(NAME): $(CFILS)
	cc $(CFLAGS) $(CFILS) -o $(NAME)

all: $(NAME)


clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)


re:	clean fclean	