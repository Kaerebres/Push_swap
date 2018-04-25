/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:16:13 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:16:15 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rra_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	if (*len_b)
		i = tab_b[0];
	i = 0;
	if (!(*len_a))
		return ;
	while (i < *len_a - 1)
		i++;
	swap = tab_a[i];
	i--;
	while (i >= 0)
	{
		tab_a[i + 1] = tab_a[i];
		i--;
	}
	tab_a[0] = swap;
}

void	rrb_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	if (*len_a)
		i = tab_a[0];
	i = 0;
	if (!(*len_b))
		return ;
	while (i < *len_b - 1)
		i++;
	swap = tab_b[i];
	i--;
	while (i >= 0)
	{
		tab_b[i + 1] = tab_b[i];
		i--;
	}
	tab_b[0] = swap;
}

void	rrr_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	rra_move(tab_a, tab_b, len_a, len_b);
	rrb_move(tab_a, tab_b, len_a, len_b);
}
