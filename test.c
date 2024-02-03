/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 18:46:46 by hibouzid          #+#    #+#             */
/*   Updated: 2024/02/02 21:03:03 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *ptr)
{
	while (ptr)
	{
	// printf("here\n");
		printf("----> %d\n", ptr->number);
		ptr = ptr->next;
	}
}
