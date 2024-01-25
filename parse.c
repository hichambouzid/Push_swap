/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:45:03 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/24 15:03:18 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_parse(char *str)
{
	int i;

	i = 0;
	if (!*str)
	return (-1);
	while (str[i])
	{
		if (((str[i] == '-' || str[i] == '+') && (str[i - 1] != '-'
			&& str[i - 1] != '+')) || (ft_isdigit(str[i]) && 
			(ft_atoi(str + i) >= 0|| ft_atoi(str + i) <= 0)))
			i++;
		else if (str[i] == ' ' && str[i + 1])
			i++;
		else
		return (-1);
	}
	return (0);
}

int ft_strleen(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int *ft_devis(char **ptr, int *len)
{
	t_el ctl;
	int *tab;

	*len = ft_strleen(ptr);
	tab = malloc(sizeof(int) * (*len));
	if (!tab)
		return (NULL);
	ctl.i = 0;
	while (ptr[ctl.i])
	{
		tab[ctl.i] = ft_atoi(ptr[ctl.i]);
		ctl.i++;
	}
	ft_free(ctl.i, ptr);
	return (tab);	
}

int ft_parse_multipl(int ac, char **av)
{
	t_el sct;

	sct.i = 1;
	while (sct.i < ac)
	{
		if (ft_parse(av[sct.i]) == -1)
		return (-1);
		sct.i++;
	}
	return (0);
}

int *ft_multipl_av(int ac, char **av)
{
	t_el ctl;

	ctl.i = 1;

	ctl.tab = malloc(sizeof(int) * (ac - 1));
	if (!ctl.tab)
		return (NULL);
	while (ctl.i < ac)
	{
		ctl.tab[ctl.i - 1] = ft_atoi(av[ctl.i]);
		ctl.i++;
	}
	return (ctl.tab);
}