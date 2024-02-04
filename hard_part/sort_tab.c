/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:54:18 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/04 12:28:36 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int	*ft_scrap_numbers(t_list *stacka)
{
	int	len;
	int	*tab;
	int	i;

	i = 0;
	len = ft_lst_size(stacka);
	tab = malloc(sizeof(int) * (len));
	if (!tab)
		return (NULL);
	while (i < len)
	{
		tab[i] = stacka->number;
		stacka = stacka->next;
		i++;
	}
	return (tab);
}

int	*ft_sort_tab(int *tab, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	ft_check_range(int *tab, int start, int end, int number)
{
	while (start < end)
	{
		if (tab[start] == number)
			return (1);
		start++;
	}
	return (0);
}

int	found_in_stack(t_list *stack, int start, int end, int *tab)
{
	while (stack)
	{
		if (ft_check_range(tab, start, end, stack->number))
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

int	get_range(int len)
{
	if (len > 5 && len <= 16)
		return (3);
	else if (len <= 100)
		return (15);
	else if (len <= 500)
		return (35);
	else
		return (45);
}

void	ft_sort_tree_part(t_list **stack, int *tab, int len)
{
	t_el	element;

	element.stackb = NULL;
	element.i = 0;
	element.j = get_range(len);
	element.stacka = *stack;
	while (*stack && element.i < len)
	{
		if (element.stacka->number < tab[element.i])
		{
			ft_push_to_stack(&element.stacka, &element.stackb, "pb\n");
			ft_rotate_stack(&element.stackb, "rb\n");
			if (element.j < len)
				element.j++;
			element.i++;
		}
		else if (ft_check_range(tab, element.i, element.j,
				element.stacka->number) == 1)
		{
			ft_push_to_stack(&element.stacka, &element.stackb, "pb\n");
			if (ft_lst_size(element.stackb) != 1
				&& element.stackb->number < element.stackb->next->number)
				ft_swap_list(&element.stackb, "sb\n");
			if (element.j < len)
				element.j++;
			element.i++;
		}
		else
			ft_rotate_stack(&element.stacka, "ra\n");
		stack = &element.stacka;
	}
	stack = &element.stacka;
	ft_find_andpush(&element.stacka, &element.stackb);
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
}
