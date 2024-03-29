/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:39:13 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/07 16:29:59 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"


int ft_is_instruction(char *str)
{
	if (!ft_strncmp(str, "ss\n", ft_strlen(str)) || !ft_strncmp(str, "rr\n", ft_strlen(str)) ||
		!ft_strncmp(str, "rra\n", ft_strlen(str)) ||
		!ft_strncmp(str, "ra\n", ft_strlen(str)) || !ft_strncmp(str, "rb\n", ft_strlen(str)) ||
		!ft_strncmp(str, "sa\n", ft_strlen(str)) || !ft_strncmp(str, "sb\n", ft_strlen(str)) 
		|| !ft_strncmp(str, "pb\n", ft_strlen(str)) || !ft_strncmp(str, "pa\n", ft_strlen(str)) || 
		!ft_strncmp(str, "rrb\n", ft_strlen(str)
		|| !ft_strncmp(str, "rrr\n", ft_strlen(str))))
		return (1);
	return (0);
}

void	ft_multipl_function(t_list **stacka, t_list **stackb, char *str)
{
	if (!ft_strncmp(str, "ss\n", 3))
	{
		ft_swap_list(stacka, NULL);
		ft_swap_list(stackb, NULL);
	}
	else if (!ft_strncmp(str, "rr\n", 3))
	{
		ft_rotate_stack(stacka, NULL);
		ft_rotate_stack(stackb, NULL);
	}
	else if (!ft_strncmp(str, "rra\n", 4))
	{
		ft_reverse_rotate_stack(stacka, NULL);
		ft_reverse_rotate_stack(stackb, NULL);
	}
	else if (!ft_strncmp(str, "pb\n", 3) || !ft_strncmp(str, "pa\n", 3))
		ft_push_to_stack(stacka, stackb, str + 1);
}

int	get_the_function(t_list **stacka, t_list **stackb, char *str)
{
	if (!ft_strncmp(str, "sa\n", 4))
		ft_swap_list(stacka, NULL);
	else if (!ft_strncmp(str, "sb\n", 3))
		ft_swap_list(stackb, NULL);
	else if (!ft_strncmp(str, "ra\n", 3))
		ft_rotate_stack(stacka, NULL);
	else if (!ft_strncmp(str, "rb\n", 3))
		ft_rotate_stack(stackb, NULL);
	else if (!ft_strncmp(str, "rra\n", 4))
		ft_reverse_rotate_stack(stacka, NULL);
	else if (!ft_strncmp(str, "rrb\n", 4))
		ft_reverse_rotate_stack(stackb, NULL);
	else if (!ft_strncmp(str, "ss\n", 3) || !ft_strncmp(str, "rr\n", 3)
		|| !ft_strncmp("rrr\n", "rrr\n", 4) || !ft_strncmp(str, "pb\n", 3)
		|| !ft_strncmp(str, "pa\n", 3))
		ft_multipl_function(stacka, stackb, str);
	
	return (ft_is_instruction(str));
}

void	ft_free_tow(t_list **stacka, t_list **stackb)
{
	ft_free_stack(stacka);
	ft_free_stack(stackb);
}

int	main(int ac, char **av)
{
	t_el	sct;
	char	*str;

	if (ac < 2)
		return (ft_putstr_fd("Error\n", 2));
	sct.stackb = NULL;
	sct.stacka = ft_creat_stack(ac, av);
	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		if (get_the_function(&sct.stacka, &sct.stackb, str) == 0)
		{
			ft_free_tow(&sct.stacka, &sct.stackb);
			return (ft_putstr_fd("Error\n", 2));
		}
		free(str);
	}
	if (ft_stack_sorted(sct.stacka) && sct.stackb == NULL)
	{
		ft_free_tow(&sct.stacka, &sct.stackb);
		return (ft_putstr_fd("OK\n", 1));
	}
	ft_putstr_fd("KO\n", 1);
}
