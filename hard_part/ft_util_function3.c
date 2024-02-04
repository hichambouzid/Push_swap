/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_function3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:07:47 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/04 18:11:06 by hibouzid         ###   ########.fr       */
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
