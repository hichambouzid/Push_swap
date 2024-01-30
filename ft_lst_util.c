/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <hibouzid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:23:05 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/30 15:46:45 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int num)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->number = num;
	new_node->next = NULL;
	return (new_node);
}

t_list	*ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_list **ptr, t_list *s)
{
	t_list	*save;

	if (!*ptr && s)
	{
		*ptr = s;
		return ;
	}
	save = *ptr;
	save = ft_lst_last(save);
	save->next = s;
}
// int main()
// {
// 	t_list *ptr;

// 	ptr = ft_lstnew(8);
// 	printf("----> %d\n", ptr->number);
// 	printf("----> %s\n", ptr->next);
// }

int	ft_stack_sorted(t_list *stack)
{
	t_list	*tmp;

	while (stack)
	{
		tmp = stack->next;
		while (tmp)
		{
			if (stack->number > tmp->number)
				return (0);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
	return (1);
}

int	ft_lst_size(t_list *ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}
