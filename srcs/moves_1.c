/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:16:01 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:16:02 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sa_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;

	if ((*len_a) <= 1)
		return ;
	if (*len_b)
		swap = tab_b[0];
	swap = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = swap;
}

void	sb_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;

	if ((*len_b) <= 1)
		return ;
	if (*len_a)
		swap = tab_a[0];
	swap = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = swap;
}

void	ss_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	sa_move(tab_a, tab_b, len_a, len_b);
	sb_move(tab_a, tab_b, len_a, len_b);
}

void	pa_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	i = 0;
	if (!(*len_b))
		return ;
	swap = tab_b[0];
	while (i < (*len_b) - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	i = *len_a;
	while (i > 0)
	{
		if ((*len_a) >= 1)
			tab_a[i] = tab_a[i - 1];
		i--;
	}
	tab_a[0] = swap;
	(*len_b)--;
	(*len_a)++;
}

void	pb_move(int *tab_a, int *tab_b, int *len_a, int *len_b)
{
	int		swap;
	int		i;

	i = 0;
	if ((*len_a) == 0)
		return ;
	swap = tab_a[0];
	while (i < (*len_a) - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	i = *len_b;
	while (i > 0)
	{
		if ((*len_b) >= 1)
			tab_b[i] = tab_b[i - 1];
		i--;
	}
	tab_b[0] = swap;
	(*len_b)++;
	(*len_a)--;
}
