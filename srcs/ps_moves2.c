/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:38:38 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:38:41 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	sa_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;

	if (data->len_b)
		swap = tab_b[0];
	swap = data->len_a;
	swap = tab_a[0];
	tab_a[0] = tab_a[1];
	tab_a[1] = swap;
	moves = save_and_add(moves, "sa\0");
}

void	sb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;

	if (data->len_a)
		swap = tab_a[0];
	swap = data->len_a;
	swap = tab_b[0];
	tab_b[0] = tab_b[1];
	tab_b[1] = swap;
	moves = save_and_add(moves, "sb\0");
}

void	ss_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	sa_move(tab_a, tab_b, data, moves);
	sb_move(tab_a, tab_b, data, moves);
}

void	pa_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	i = 0;
	if (!(data->len_b))
		return ;
	swap = tab_b[0];
	while (i < data->len_b - 1)
	{
		tab_b[i] = tab_b[i + 1];
		i++;
	}
	i = data->len_a;
	while (i > 0)
	{
		if (data->len_a >= 1)
			tab_a[i] = tab_a[i - 1];
		i--;
	}
	tab_a[0] = swap;
	(data->len_b) -= 1;
	(data->len_a) += 1;
	moves = save_and_add(moves, "pa\0");
}

void	pb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	i = 0;
	if ((data->len_a) == 0)
		return ;
	swap = tab_a[0];
	while (i < data->len_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	i = data->len_b;
	while (i > 0)
	{
		if (data->len_b >= 1)
			tab_b[i] = tab_b[i - 1];
		i--;
	}
	tab_b[0] = swap;
	(data->len_b) += 1;
	(data->len_a) -= 1;
	moves = save_and_add(moves, "pb\0");
}
