/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 16:05:34 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/06 22:03:33 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int ft_multiple_av_valid(int ac, char **av)
// {
// 	int i;
// 	int j;
// 	int count;

// 	i = 1;
// 	count = 0;
// 	while (i < ac)
// 	{
// 		j = 0;
// 		while (av[i][j])
// 		{
// 	// printf("im here\n");
// 			if ((av[i][j] == 32) || (av[i][j] >= 9 && av[i][j] <= 13))
// 				j++;
// 			else if ((j == 0 && ft_isdigit(av[i][j])) || (ft_isdigit(av[i][j]) && av[i][j - 1] == 32))
// 			{
// 				count++;
// 				j++;
// 			}
// 			else if ((av[i][j] == '+' || av[i][j] == '-') && ft_isdigit(av[i][j + 1]))
// 			{
// 				count++;
// 				j++;
// 			}
// 			else if (ft_isdigit(av[i][j]))
// 			j++;
// 			else
// 				return (0);
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// int ft_squip(char *av, int j)
// {
// 	while (av[j] == ' ' || av[j] == '\t')
// 		j++;
// 	return (j);
// }

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

char *ft_all_av(int ac, char **av)
{
	int i;
	char *str;

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
