/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:38:44 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/23 19:40:04 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include "libft_cursus/libft.h"

typedef struct elemet
{
	int i;
	int len;
	int **ptr;
	int *tab;
	long num;
	int sign;
} t_el;

typedef struct s_list
{
	int number;
	struct s_list *next;
} t_list;

#define INT_MIN -2147483648 
#define INT_MAX 2147483647

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int	ft_strlen(const char *s);
int ft_parse(char *av);
int *ft_devis(char **ptr, int *len);
int ft_parse_multipl(int ac, char **av);
int ft_strleen(char **ptr);
int	ft_atoi(char *str);
int *ft_multipl_av(int ac, char **av);
int	ft_isdigit(int c);
t_list *ft_lstnew(int num);

t_list *ft_lst_last(t_list *lst);
void ft_lst_add_back(t_list **ptr, t_list *s);
t_list *ft_creat_stacka(int *tab, int len);
void ft_print_list(t_list *ptr);
t_list *ft_creat_stackb(int len);

#endif
