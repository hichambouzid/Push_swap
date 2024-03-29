/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:38:44 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/06 21:48:04 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// use a linked list as a stack
typedef struct s_list
{
	int				number;
	struct s_list	*next;
}					t_list;

// struct for small lines in code
typedef struct elemet
{
	int				i;
	int				len;
	// static int		index;
	int				j;
	int				min;
	int				max;
	int				**ptr;
	int				*tab;
	long			num;
	int				sign;
	struct s_list	*stacka;
	struct s_list	*stackb;
}					t_el;
# define INT_MIN -2147483648
# define INT_MAX 2147483647

// some util fucntions
int					ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
int					ft_strlen(char *s);
int					ft_parse(char *av);
int					*ft_devis(char **ptr, int *len);
int					ft_parse_multipl(int ac, char **av);
int					ft_strleen(char **ptr);
int					ft_atoi(char *str);
int					*ft_multipl_av(int ac, char **av);
int					ft_isdigit(int c);
int					ft_min(t_list *list);
int					ft_max(t_list *list);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_all_av(int ac, char **av);
// check the params given in the argument if valid
void				ft_check_array(int *tab, int len_tab);
char				**ft_free(int index, char **ptr);

// creat a stack and the moves & free stack
t_list				*ft_lst_last(t_list *lst);
void				ft_lst_add_back(t_list **ptr, t_list *s);
void				ft_swap_list(t_list **stacka, char *str);
t_list				*ft_creat_stacka(int *tab, int len);
void				ft_reverse_rotate_stack(t_list **stack, char *str);
void				ft_rotate_stack(t_list **stack, char *str);
t_list				*ft_lstnew(int num);
void				ft_free_stack(t_list **a);
int					ft_stack_sorted(t_list *ptr);
int					ft_lst_size(t_list *ptr);
void				ft_sort_list(t_list **stack, int len);
void				ft_push_to_stack(t_list **stacka, t_list **stackb,
						char *str);
t_list				*ft_sort_four(t_list **stack);
int					*ft_sort_tab(int *tab, int len);
int					*ft_scrap_numbers(t_list *stacka);
void				ft_sort_tree_part(t_list **stack, int *tab, int len);
t_list				*ft_sort_tree(t_list **stack);
void				ft_find_andpush(t_list **stack, t_list **stackb);
int					ft_index(t_list *stack, int num);
int					get_range(int len);
int					found_in_stack(t_list *stack, int start, int end, int *tab);
int					ft_check_range(int *tab, int start, int end, int number);
int					get_range(int len);
t_list				*ft_creat_stack(int ac, char **av);
// print the stack for testing
void				ft_print_list(t_list *ptr);

#endif
