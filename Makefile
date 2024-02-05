NAME= push_swap

NAME_BONUS= checker

CFILS= main.c ft_atoi.c parse.c ft_isdigit.c ft_putstr_fd.c\
			ft_stack.c ft_strlen.c ft_split.c ft_lst_util.c  test.c ft_check_tab.c ft_sort_list.c ft_util_function.c\
			ft_strncmp.c ./hard_part/sort_tab.c ft_util_function2.c ./hard_part/ft_util_function3.c


CFLAGS= -Wall -Wextra -Werror # -fsanitize=address -g

# echo "i'm here\n"
FILS= = ft_checker.c get_next_line.c get_next_line_utils.c ft_atoi.c parse.c ft_isdigit.c ft_putstr_fd.c\
			ft_stack.c ft_strlen.c ft_split.c ft_lst_util.c  test.c ft_check_tab.c ft_sort_list.c ft_util_function.c\
			ft_strncmp.c ./hard_part/sort_tab.c ft_util_function2.c ./hard_part/ft_util_function3.c

OBJS=$(CFILS:.c=.o)

#$(OBJS_BONUS):$(FILS)
	
$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)

all: $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	cc $(CFLAGS) $(FILS) -o checker

bonus: $(NAME) $(NAME_BONUS)
	

clean:
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)


re:	fclean all
