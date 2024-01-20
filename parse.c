/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:45:03 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/20 17:14:21 by hibouzid         ###   ########.fr       */
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
			&& str[i - 1] != '+')) || ft_isdigit(str[i]))
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

int *ft_devis(char **ptr)
{
	int i;
	int len;
	int *tab;

	len = ft_strleen(ptr);
	tab = malloc(sizeof(int) * len);
	if (!tab)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		tab[i] = ft_atoi(ptr[i]);
		i++;
	}
	return (tab);	
}