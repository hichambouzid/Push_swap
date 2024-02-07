/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:58 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/07 14:08:10 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_el	sct;

	if (ac < 2)
		return (0);
	sct.stacka = ft_creat_stack(ac, av);
	if (sct.stacka && !ft_stack_sorted(sct.stacka))
	{
		printf("%p\n", &sct.stacka);
		if (ft_lst_size(sct.stacka) == 2)
			ft_swap_list(&sct.stacka, "sa\n");
		else
			ft_sort_list(&sct.stacka, ft_lst_size(sct.stacka));
	}
	system("leaks push_swap");
}
