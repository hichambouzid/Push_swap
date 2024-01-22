/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hibouzid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 00:38:44 by hibouzid          #+#    #+#             */
/*   Updated: 2024/01/22 11:54:08 by hibouzid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft_cursus/libft.h"

typedef struct elemet
{
	int i;
	int len;
	int **ptr;
	int *tab;
	long num;
	int sign;
} t_el;

#define INT_MIN -2147483648 
#define INT_MAX 2147483647
int ft_parse(char *av);
int *ft_devis(char **ptr);
int ft_parse_multipl(int ac, char **av);
int ft_strleen(char **ptr);
int	ft_atoi(char *str);
int *ft_multipl_av(int ac, char **av);

#endif
