/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:58 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/23 19:26:56 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_el sct;
	t_list *s;

	if (ac == 2 && !ft_parse(av[1]))
	{
		sct.tab = ft_devis(ft_split(av[1], ' '), &sct.len);
		s = ft_creat_stacka(sct.tab, sct.len);
		ft_print_list(s);
		
	}
	else if (ac > 2 && !ft_parse_multipl(ac, av))
	{
		sct.tab = ft_multipl_av(ac, av);
		s = ft_creat_stacka(sct.tab, ac - 1);
		ft_print_list(s);
	}
	else
		printf("Error\n");
}