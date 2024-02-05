/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:39:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/05 10:57:56 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

int main(int ac, char **av)
{
	t_el sct;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	sct.stacka = ft_creat_stacka(ac, av);
	if (sct.stacka && !ft_stack_sorted(sct.stacka))
	
}