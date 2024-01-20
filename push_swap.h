/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:38:44 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/20 17:06:33 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include "libft_cursus/libft.h"

typedef struct elemet
{
	int i;
	int *len;
	int **ptr;
	int *tab;
} t_el;

int ft_parse(char *str);
int *ft_devis(char **ptr);

#endif
