/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 19:40:48 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/05 15:40:54 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_array(int *tab, int len_tab)
{
	t_el	elem;

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

t_list	*ft_creat_stack(int ac, char **av)
{
	t_el	sct;
	
	if (ac == 2 && !ft_parse(av[1]))
	{
		sct.tab = ft_devis(ft_split(av[1], ' '), &sct.len);
		ft_check_array(sct.tab, sct.len);
		sct.stacka = ft_creat_stacka(sct.tab, sct.len);
	}
	else if (ac > 2 && !ft_parse_multipl(ac, av))
	{
		sct.tab = ft_multipl_av(ac, av);
		ft_check_array(sct.tab, ac - 1);
		sct.stacka = ft_creat_stacka(sct.tab, ac - 1);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (sct.stacka);
}