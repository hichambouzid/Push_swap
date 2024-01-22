/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 10:24:02 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/22 12:21:25 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	t_el ctl;

	ctl.i = 0;
	ctl.num = 0;
	ctl.sign = 1;
	
	if (str[ctl.i] == '+')
		ctl.i++;
	else if (str[ctl.i] == '-')
	{
		ctl.i++;
		ctl.sign = -1;
	}
	while (str[ctl.i] && (str[ctl.i] >= '0' && str[ctl.i] <= '9'))
	{
		ctl.num = (ctl.num * 10) + str[ctl.i] - 48;
		ctl.i++;
	}
	if (ctl.num < INT_MIN || ctl.num > INT_MAX)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (ctl.sign == -1)
		ctl.num *= -1;
	return ((int)ctl.num);
}

// #include <stdio.h>

// int main()dds
// {
// 	printf("%d\n", ft_atoi("--1234"));
// }
