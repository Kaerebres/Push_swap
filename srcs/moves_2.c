/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:16:08 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:16:10 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ra_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	if (*len_b)
		i = tab_b[0];
	i = 0;
	if (!(*len_a))
		return ;
	swap = tab_a[0];
	while (i < (*len_a) - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[i] = swap;
}

void	rb_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	if (*len_a)
		i = tab_a[0];
	i = 0;
	if (!(*len_b))
		return ;
	swap = tab_b[0];
	while (i < (*len_b) - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[i] = swap;
}

void	rr_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	ra_move(tab_a, tab_b, len_a, len_b);
	rb_move(tab_a, tab_b, len_a, len_b);
}
