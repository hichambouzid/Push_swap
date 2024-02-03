NAME= push_swap

CFILS= main.c ft_atoi.c parse.c ft_isdigit.c ft_putstr_fd.c\
			ft_stack.c ft_strlen.c ft_split.c ft_lst_util.c  test.c ft_check_tab.c ft_sort_list.c ft_util_function.c\
			ft_strncmp.c ./hard_part/sort_tab.c


CFLAGS= -Wall -Wextra -Werror #-g -fsanitize=address 

$(NAME): $(CFILS)
	cc $(CFLAGS) $(CFILS) -o $(NAME)

all: $(NAME)


clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)


re:	clean fclean	