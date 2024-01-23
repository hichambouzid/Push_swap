/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:34:34 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/23 19:39:27 by hibouzid         ###   ########.fr       */
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
	return (rt);
}

t_list *ft_creat_stackb(int len)
{
	int i;
	t_list *rt;

	i = 0;
	rt = NULL;
	while (i < len)
	{
		ft_lst_add_back(&rt, ft_lstnew(0));
		i++;
	}
	return (rt);
}