/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:05:34 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/07 14:08:46 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_list *list)
{
	int	rt;

	rt = list->number;
	while (list)
	{
		if (list->number > rt)
			rt = list->number;
		list = list->next;
	}
	return (rt);
}

int	ft_min(t_list *list)
{
	int	rt;

	rt = list->number;
	while (list)
	{
		if (list->number < rt)
			rt = list->number;
		list = list->next;
	}
	return (rt);
}

char	*ft_all_av(int ac, char **av)
{
	int		i;
	char	*str;

	str = NULL;
	i = 1;
	while (i < ac)
	{
		str = ft_strjoin(str, av[i]);
		str = ft_strjoin(str, " ");
		i++;
	}
	return (str);
}
