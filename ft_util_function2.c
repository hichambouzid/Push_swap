/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_function2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:02:46 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/04 18:03:49 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_stack(t_list **stacka, t_list **stackb, char *str)
{
	t_list	*save1;
	t_list	*save2;

	save1 = *stacka;
	save2 = *stackb;
	if (!ft_strncmp(str, "pb\n", 3))
	{
		*stacka = (*stacka)->next;
		save1->next = *stackb;
		*stackb = save1;
		ft_putstr_fd(str, 1);
	}
	else if (!ft_strncmp(str, "pa\n", 3))
	{
		*stackb = (*stackb)->next;
		save2->next = *stacka;
		*stacka = save2;
		ft_putstr_fd(str, 1);
	}
}
