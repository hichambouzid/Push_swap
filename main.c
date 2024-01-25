/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 19:08:58 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/25 21:11:33 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_creat_stack(int ac, char **av)
{
	t_el sct;

	if (ac == 2 && !ft_parse(av[1]))
	{
		sct.tab = ft_devis(ft_split(av[1], ' '), &sct.len);
		ft_check_array(sct.tab, sct.len);
		sct.stacka = ft_creat_stacka(sct.tab, sct.len);		
	}
	else if (ac > 2 && !ft_parse_multipl(ac, av))
	{
		sct.tab = ft_multipl_av(ac, av);
		ft_check_array(sct.tab, ac - 1);
		sct.stacka = ft_creat_stacka(sct.tab, ac - 1);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		return (NULL);
	}
	return (sct.stacka);
}


int main(int ac, char **av)
{
	t_el sct;

	if (ac == 1 || (ac == 2 && !av[1][0]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);		
	}
	sct.stacka = ft_creat_stack(ac, av);
	if (sct.stacka && !ft_stack_sorted(sct.stacka))
	{
		printf("the size of linked list : %d\n", ft_lst_size(sct.stacka));
	}
	return (write(1, "hello world\n", 12));
	// ft_rotate_stack(&sct.stacka);
	// ft_print_list(sct.stacka);
	// ft_free_stack(&sct.stacka);
	// ft_print_list(sct.stacka);

}