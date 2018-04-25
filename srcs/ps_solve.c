/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 10:55:36 by csimon            #+#    #+#             */
/*   Updated: 2017/10/09 10:55:38 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

int		get_higher(int *tab, t_lens *data)
{
	int		i;
	int		result;
	int		index;

	index = 0;
	result = -10000;
	i = 0;
	while (i < data->len_b)
	{
		if (tab[i] > result)
		{
			result = tab[i];
			index = i;
		}
		i++;
	}
	return (index);
}

void	fetch_higher(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		higher;

	higher = get_higher(tab_b, data);
	if (higher > (data->len_b / 2))
		while (higher < data->len_b)
		{
			rrb_move(tab_a, tab_b, data, moves);
			higher++;
		}
	else
		while (higher > 0)
		{
			rb_move(tab_a, tab_b, data, moves);
			higher--;
		}
	pa_move(tab_a, tab_b, data, moves);
}

int		is_sorted(int *tab, int len)
{
	int		i;

	i = 0;
	while (i < len - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_all_a(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	if (is_sorted(tab_a, data->len_a))
		return ;
	if (data->len_a <= 3)
	{
		sort_a(tab_a, tab_b, data, moves);
		return ;
	}
	data->median = quick_medi(tab_a, 0, data->len_a);
	sort_med(tab_a, tab_b, data, moves);
	sort_all_a(tab_a, tab_b, data, moves);
	while (data->len_b)
		fetch_higher(tab_a, tab_b, data, moves);
}

void	sort_a(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	if (data->len_a == 2 && tab_a[0] > tab_a[1])
		sa_move(tab_a, tab_b, data, moves);
	else if (data->len_a >= 3)
	{
		if (tab_a[0] > tab_a[1] && tab_a[0] > tab_a[2])
		{
			if (tab_a[1] > tab_a[2])
			{
				sa_move(tab_a, tab_b, data, moves);
				rra_move(tab_a, tab_b, data, moves);
			}
			else
				ra_move(tab_a, tab_b, data, moves);
		}
		else if (tab_a[0] > tab_a[2])
			rra_move(tab_a, tab_b, data, moves);
		else if (tab_a[0] > tab_a[1])
			sa_move(tab_a, tab_b, data, moves);
		else if (tab_a[1] > tab_a[2])
		{
			rra_move(tab_a, tab_b, data, moves);
			sa_move(tab_a, tab_b, data, moves);
		}
	}
}
