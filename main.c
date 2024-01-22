/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:58 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/22 12:48:43 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_el sct;

	if (ac == 2 && !ft_parse(av[1]))
	{
		sct.tab = ft_devis(ft_split(av[1], ' '));
	}
	else if (ac >= 2 && !ft_parse_multipl(ac, av))
	{
		sct.tab = ft_multipl_av(ac, av);
	}
	else
		printf("hello world\n");
// 	ft_putstr_fd("Error\n", 2);
// 	exit(-1);
}