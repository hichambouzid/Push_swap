/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:54:18 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/04 18:45:53 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void	ft_increment(int *start, int *end, int len)
{
	*start += 1;
	if (*end < len)
		*end += 1;
}

void	ft_sort_tree_part(t_list **stack, int *tab, int len)
{
	t_el	element;

	element.stackb = NULL;
	element.i = 0;
	element.j = get_range(len);
	element.stacka = *stack;
	while (element.stacka && element.i < len)
	{
		if (element.stacka->number < tab[element.i])
		{
			ft_push_to_stack(&element.stacka, &element.stackb, "pb\n");
			ft_rotate_stack(&element.stackb, "rb\n");
			ft_increment(&element.i, &element.j, len);
		}
		else if (ft_check_range(tab, element.i, element.j,
				element.stacka->number) == 1)
		{
			ft_push_to_stack(&element.stacka, &element.stackb, "pb\n");
			ft_increment(&element.i, &element.j, len);
		}
		else
			ft_rotate_stack(&element.stacka, "ra\n");
	}
	ft_find_andpush(&element.stacka, &element.stackb);
	free(tab);
}

int	ft_index(t_list *stack, int num)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack->number == num)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	ft_find_andpush(t_list **stack, t_list **stackb)
{
	while (*stackb)
	{
		if (ft_max(*stackb) == (*stackb)->number)
			ft_push_to_stack(stack, stackb, "pa\n");
		else if ((*stackb)->next && ft_max(*stackb) == (*stackb)->next->number)
			ft_swap_list(stackb, "sb\n");
		else if (ft_index(*stackb, ft_max(*stackb)) < ft_lst_size(*stackb) / 2)
			ft_rotate_stack(stackb, "rb\n");
		else
			ft_reverse_rotate_stack(stackb, "rrb\n");
	}
	ft_free_stack(stack);
}
