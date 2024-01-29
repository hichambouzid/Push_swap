/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 11:19:56 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/30 00:37:19 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_sort_tree(t_list **stack)
// {
// 	t_list *tmp;
// 	// t_list *other;

// 	tmp = *stack;
// 	while (!ft_stack_sorted(*stack))
// 	{
// 		// other = ft_lst_last(*stack);
// 		stack = &tmp;
// 		if (tmp->number > tmp->next->number)
// 			ft_swap_list(&tmp, "sa\n");
// 		else if (ft_stack_sorted(tmp->next))
// 			ft_rotate_stack(&tmp, "ra\n");
// 		else if (tmp->next->next->number < tmp->number)
// 			ft_reverse_rotate_stack(&tmp, "rra\n");
// 		else
// 			ft_reverse_rotate_stack(&tmp, "rra\n");
// 	}
// 		// ft_print_list(*stack);
// }

t_list *ft_sort_tree(t_list **stack)
{
	t_list *tmp;
	// t_list *other;

	tmp = *stack;
	while (!ft_stack_sorted(*stack))
	{
		// other = ft_lst_last(*stack);
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
	// ft_print_list(*stack);
	return (*stack);
}
// void ft_sort_five(t_list **stack)
// {
// 	int min;
// 	// int max;
// 	t_list *other;
// 	t_list *tmp;
// 	t_list *stackb;
// 	// min = ft_min(*stack);
// 	// max = ft_max(*stack);
// 	tmp = *stack;
// 	stackb = NULL;
// 	while (!ft_stack_sorted(*stack))
// 	{
// 		other = ft_lst_last(*stack);
// 		min = ft_min(*stack);
// 		if (tmp->number > tmp->next->number)
// 			ft_swap_list(&tmp, "sa\n");
// 		else if (ft_stack_sorted(tmp->next) && !ft_stack_sorted(tmp))
// 			ft_rotate_stack(&tmp, "ra\n");
// 		else if (tmp->number > other->number)
// 			ft_reverse_rotate_stack(&tmp, "rra\n");
// 		else if (tmp->number == min)
// 			ft_push_to_stack(&tmp, &stackb, "pa\n");
// 		stack = &tmp;
// 	}
// 	if (ft_lst_size(stackb) == 2 && stackb->number < stackb->next->number)
// 	{
// 		ft_swap_list(&stackb, "sb\n");
// 	// printf("====here====\n");
// 	}
// 	ft_push_to_stack(&tmp, &stackb, "pb\n");
// 	// ft_push_to_stack(&tmp, &stackb, "pb\n");
// 	*stack = tmp;
// }

t_list *ft_sort_four(t_list **stack)
{
	t_list *tmp;
	// t_list *last;
	t_el element;

	// element = NULL;
	element.min = ft_min(*stack);
	element.max = ft_max(*stack);
	tmp = *stack;
	element.stackb = NULL;
	// printf("the adress %p\n", stack);
	while (!ft_stack_sorted(*stack) && !element.stackb)
	{
		if (tmp->number == element.min || tmp->number == element.max)
			ft_push_to_stack(&tmp, &element.stackb, "pb\n");
		else if (tmp->next->number == element.min || tmp->next->number == element.max)
			ft_swap_list(&tmp, "sa\n");
		else
			ft_reverse_rotate_stack(&tmp, "rra\n");
		stack = &tmp;
	}

	*stack = ft_sort_tree(&tmp);
	if (element.stackb && element.stackb->number == element.max)
	{
		ft_push_to_stack(stack, &element.stackb, "pa\n");
		ft_rotate_stack(stack, "ra\n");
	}

	else if (element.stackb && element.stackb->number == element.min)
		ft_push_to_stack(stack, &element.stackb, "pa\n");
	// ft_print_list(*stack);
	return (*stack);
}

void ft_sort_list(t_list **stack, int len)
{
	if (len <= 3)
		ft_sort_tree(stack);
	if (len <= 4)
		*stack = ft_sort_four(stack);
	// if (ft_stack_sorted(*stack))
		// printf("yees\n");
	// ft_print_list(*stack);
	// ft_free_stack(stack);
	// if (ft_stack_sorted(*stack))
	// return (*stack);
}

void ft_push_to_stack(t_list **stacka, t_list **stackb, char *str)
{
	t_list *save1;
	t_list *save2;

	save1 = *stacka;
	save2 = *stackb;
	if (!ft_strncmp(str, "pb\n", 4))
	{
		*stacka = (*stacka)->next;
		save1->next = *stackb;
		*stackb = save1;
	}
	else if (!ft_strncmp(str, "pa\n", 4))
	{
		*stackb = (*stackb)->next;
		save2->next = *stacka;
		*stacka = save2;
	}
	ft_putstr_fd(str, 1);
}