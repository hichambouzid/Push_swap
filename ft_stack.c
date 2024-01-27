/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:34:34 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/27 16:44:14 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_creat_stacka(int *tab, int len)
{
	t_el el;
	t_list *rt;

	rt = NULL;
	el.i = 0;
	// printf("len is %d\n", len);
	while (el.i < len)
	{
		ft_lst_add_back(&rt, ft_lstnew(tab[el.i]));
		el.i++;
	}
	free(tab);
	return (rt);
}

// t_list *ft_creat_stackb(int len)
// {
// 	int i;
// 	t_list *rt;

// 	i = 0;
// 	rt = NULL;
// 	while (i < len)
// 	{
// 		ft_lst_add_back(&rt, ft_lstnew(0));
// 		i++;
// 	}
// 	return (rt);
// }

void ft_swap_list(t_list **stack, char *str)
{
	t_list *tmp;

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	tmp->next = *stack;
	*stack = tmp;
	ft_putstr_fd(str, 1);
}

void ft_reverse_rotate_stack(t_list **stack, char *str)
{
	t_list *tmp;

	tmp = *stack;
	while ((*stack)->next)
		*stack = (*stack)->next;
	(*stack)->next = tmp;
	// (*stack) = tmp;
	tmp = (*stack);
	while (tmp->next)
	{
		if (*stack == tmp->next)
		{
			tmp->next = NULL;
			break ;
		}
		tmp = tmp->next;
	}
	if (str)
		ft_putstr_fd(str, 1);
}

void ft_rotate_stack(t_list **stack, char *str)
{
	t_list *tmp;
	t_list *mv;

	tmp = *stack;
	mv = (*stack)->next;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *stack;
	*stack = mv;
	tmp->next->next = NULL;
	if (str)
		ft_putstr_fd(str, 1);
}

void ft_free_stack(t_list **a)
{
	t_list *tmp;

	tmp = *a;
	
	while ((*a))
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

int ft_stack_sorted(t_list *stack)
{
	t_list *tmp;
	
	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->number > tmp->number)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int ft_lst_size(t_list *ptr)
{
	int i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

