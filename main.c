/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:58 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/20 17:13:08 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_el sct;

	if (ac == 2 && !ft_parse(av[1]))
	{
		str.tab = ft_devis(ft_split(av[1], ' '), s);
		for (int i = 0; str.tab[i]; i++)
			printf("%d\n", str.tab[i]);
	}
	ft_putstr_fd("Error\n", 2);
	exit(-1);
}