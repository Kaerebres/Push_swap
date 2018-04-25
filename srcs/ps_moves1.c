/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:38:33 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:38:35 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	rb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	if (data->len_a)
		i = tab_a[0];
	i = 0;
	if (!data->len_b)
		return ;
	swap = tab_b[0];
	while (i < data->len_b - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	tab_b[i] = swap;
	moves = save_and_add(moves, "rb\0");
}

void	rr_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	ra_move(tab_a, tab_b, data, moves);
	rb_move(tab_a, tab_b, data, moves);
}

void	rra_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	if (data->len_b)
		i = tab_b[0];
	i = 0;
	if (!data->len_a)
		return ;
	while (i < data->len_a - 1)
		i++;
	swap = tab_a[i];
	i--;
	while (i >= 0)
	{
		tab_a[i + 1] = tab_a[i];
		i--;
	}
	tab_a[0] = swap;
	moves = save_and_add(moves, "rra\0");
}

void	rrb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	if (data->len_a)
		i = tab_a[0];
	i = 0;
	if (!data->len_b)
		return ;
	while (i < data->len_b - 1)
		i++;
	swap = tab_b[i];
	i--;
	while (i >= 0)
	{
		tab_b[i + 1] = tab_b[i];
		i--;
	}
	tab_b[0] = swap;
	moves = save_and_add(moves, "rrb\0");
}

void	rrr_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	rra_move(tab_a, tab_b, data, moves);
	rrb_move(tab_a, tab_b, data, moves);
}
