/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:19:56 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/27 16:55:47 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_sort_tree(t_list **stack)
{
	t_list *tmp;

	tmp = *stack;
	while (!ft_stack_sorted(*stack))
	{
		if (tmp->number > tmp->next->number)
			ft_swap_list(&tmp, "sa\n");
		else if (ft_stack_sorted(tmp->next) && tmp->number > tmp->next->number && tmp->next->next->number < tmp->number)
			ft_rotate_stack(&tmp, "ra\n");
		else if (tmp->next->next->number < tmp->number)
			ft_reverse_rotate_stack(&tmp, "rra\n");
	}
	ft_free_stack(stack);
}

void ft_sort_five(t_list **stack)
{
	int min;
	int max;
	t_list *stackb;
	t_list *tmp;
	
	min = ft_min(*stack);
	max = ft_max(*stack);
	tmp = *stack;
	while (!ft_stack_sorted(*stack))
	{
		if ()
	}
}

void ft_sort_list(t_list **stack, int len)
{
	if (len <= 3)
		ft_sort_tree(stack);
	else if (len <= 5)
		ft_sort_five(stack);
	
}