/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:19:56 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/01 18:10:45 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sort_tree(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (!ft_stack_sorted(*stack))
	{
		stack = &tmp;
		if (tmp->number > tmp->next->number)
			ft_swap_list(&tmp, "sa\n");
		else if (ft_stack_sorted(tmp->next))
			ft_rotate_stack(&tmp, "ra\n");
		else if (tmp->next->next->number < tmp->number)
			ft_reverse_rotate_stack(&tmp, "rra\n");
		else
			ft_reverse_rotate_stack(&tmp, "rra\n");
	}
	return (*stack);
}

t_list	*ft_sort_four(t_list **stack)
{
	t_list	*tmp;
	t_el	element;

	element.min = ft_min(*stack);
	element.max = ft_max(*stack);
	tmp = *stack;
	element.stackb = NULL;
	while (!ft_stack_sorted(*stack) && !element.stackb)
	{
		if (tmp->number == element.min || tmp->number == element.max)
			ft_push_to_stack(&tmp, &element.stackb, "pb\n");
		else if (tmp->next->number == element.min
			|| tmp->next->number == element.max)
			ft_swap_list(&tmp, "sa\n");
		else
			ft_reverse_rotate_stack(&tmp, "rra\n");
		stack = &tmp;
	}
	*stack = ft_sort_tree(&tmp);
	ft_push_to_stack(stack, &element.stackb, "pa\n");
	if ((*stack)->number == element.max)
		ft_rotate_stack(stack, "ra\n");
	return (*stack);
}

t_list	*ft_push_last(t_list **stack, t_el element)
{
	ft_push_to_stack(stack, &element.stackb, "pa\n");
	if ((*stack)->number == element.max)
		ft_rotate_stack(stack, "ra\n");
	ft_push_to_stack(stack, &element.stackb, "pa\n");
	if ((*stack)->number == element.max)
		ft_rotate_stack(stack, "ra\n");
	return (*stack);
}

t_list	*ft_sort_five(t_list **stack)
{
	t_el	element;

	element.stackb = NULL;
	element.stacka = *stack;
	element.min = ft_min(*stack);
	element.max = ft_max(*stack);
	while (!ft_stack_sorted(*stack) && ft_lst_size(element.stackb) != 2)
	{
		if (element.stacka->number == element.min
			|| element.stacka->number == element.max)
			ft_push_to_stack(&element.stacka, &element.stackb, "pb\n");
		else if (element.stacka->next->number == element.min
			|| element.stacka->next->number == element.max)
			ft_swap_list(&element.stacka, "sa\n");
		else
			ft_reverse_rotate_stack(&element.stacka, "rra\n");
		stack = &element.stacka;
	}
	*stack = ft_sort_tree(stack);
	*stack = ft_push_last(stack, element);
	return (*stack);
}

void	ft_sort_list(t_list **stack, int len)
{
	int *tab;
	if (len <= 3)
		ft_sort_tree(stack);
	else if (len <= 4)
		*stack = ft_sort_four(stack);
	else if (len <= 5)
		*stack = ft_sort_five(stack);
	else if (len > 5 && len < 16)
	{
		tab = ft_sort_tab(ft_scrap_numbers(*stack), ft_lst_size(*stack));
			
	}
}

void	ft_push_to_stack(t_list **stacka, t_list **stackb, char *str)
{
	t_list	*save1;
	t_list	*save2;

	save1 = *stacka;
	save2 = *stackb;
	if (!ft_strncmp(str, "pb\n", 4) && *stacka)
	{
		*stacka = (*stacka)->next;
		save1->next = *stackb;
		*stackb = save1;
		ft_putstr_fd(str, 1);
	}
	else if (!ft_strncmp(str, "pa\n", 4) && *stackb)
	{
		*stackb = (*stackb)->next;
		save2->next = *stacka;
		*stacka = save2;
		ft_putstr_fd(str, 1);
	}
}
