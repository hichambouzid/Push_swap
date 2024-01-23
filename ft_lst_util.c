/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:23:05 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/23 19:10:02 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_lstnew(int num)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
	return (NULL);
	new_node->number = num;
	new_node->next = NULL;
	return (new_node);
}

t_list *ft_lst_last(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void ft_lst_add_back(t_list **ptr, t_list *s)
{
	t_list *save;

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