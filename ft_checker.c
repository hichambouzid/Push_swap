/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:39:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/05 13:28:41 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

void get_the_function(t_list **stacka, t_list **stackb, char *str)
{
	if (!ft_strncmp("sa\n", "sa\n", 3))
		ft_swap_list(stacka, NULL);
	else if (!ft_strncmp("sb\n", "sb\n", 3))
		ft_swap_list(stackb, NULL);
	else if (!ft_strncmp("ra\n", "ra\n", 3))
		ft_rotate_stack(stacka, NULL);
	else if (!ft_strncmp("rb\n", "rb\n", 3))
		ft_rotate_stack(stackb, NULL);
	else if (!ft_strncmp("rra\n", "rra\n", 4))
		ft_reverse_rotate_stack(stacka, NULL);
	else if (!ft_strncmp("rrb\n", "rrb\n", 4))
		ft_reverse_rotate_stack(stackb, NULL);
	else if (!ft_strncmp("ss\n", "ss\n", 3))
	{
		ft_swap_list(stacka, NULL);
		ft_swap_list(stackb, NULL);
	}
	else if (!ft_strncmp("rr\n", "rr\n", 3))
	{
		ft_rotate_stack(stacka, NULL);
		ft_rotate_stack(stackb, NULL);
	}
	else if (!ft_strncmp("rrr\n", "rrr\n", 4))
	{
		ft_reverse_rotate_stack(stacka, NULL);
		ft_reverse_rotate_stack(stackb, NULL);
	}
	else
		*str += 1;
}

int main(int ac, char **av)
{
	t_el sct;
	char *str;

	if (ac < 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	sct.stackb = NULL;
	sct.stacka = ft_creat_stack(ac, av);
	while (!ft_stack_sorted(sct.stacka))
	{
		str = get_next_line(0);
		get_the_function(&sct.stacka, &sct.stackb, str);
		if (ft_stack_sorted(sct.stacka) && !sct.stackb)
			ft_putstr_fd("OK\n", 1);
	}
	ft_putstr_fd("KO\n", 1);		
}