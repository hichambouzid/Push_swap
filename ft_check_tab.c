/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:40:48 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/24 15:05:02 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void ft_check_array(int *tab, int len_tab)
{
	t_el elem;
	
	elem.i = 0;
	while (elem.i < len_tab)
	{
		elem.j = elem.i + 1;
		while (elem.j < len_tab)
		{
			if (tab[elem.j] == tab[elem.i])
			{
				free(tab);
				ft_putstr_fd("Error\n", 2);
				exit(-1);
			}
			elem.j++;
		}
		elem.i++;
	}
}