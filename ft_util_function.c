/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:53:47 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/27 15:57:21 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_max(t_list *list)
{
	int rt;

	rt = list->number;
	while (list)
	{
		if (list->number > rt)
			rt = list->number;
		list = list->next;
	}
	return (rt);
}

int ft_min(t_list *list)
{
	int rt;

	rt = list->number;
	while (list)
	{
		if (list->number < rt)
			rt = list->number;
		list = list->next;
	}
	return (rt);
}