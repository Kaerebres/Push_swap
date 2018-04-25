/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_various.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:38:49 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:38:51 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

int		check_closer(int *tab, t_lens *data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tab[0] <= data->median)
		return (0);
	while (i < data->len_a)
	{
		if (tab[i] <= data->median)
			return (1);
		if (tab[data->len_a - j - 1] <= data->median)
			return (2);
		i++;
		j++;
	}
	return (3);
}

void	sort_med(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		i;

	i = 0;
	while (data->len_a >= 3)
	{
		if (tab_a[0] <= data->median)
			pb_move(tab_a, tab_b, data, moves);
		else if (check_closer(tab_a, data) == 1)
			while (tab_a[0] > data->median)
				ra_move(tab_a, tab_b, data, moves);
		else if (check_closer(tab_a, data) == 2)
			while (tab_a[0] > data->median)
				rra_move(tab_a, tab_b, data, moves);
		else if (check_closer(tab_a, data) == 3)
			break ;
		i++;
	}
}

t_mvl	*save_and_add(t_mvl *begin, char *str)
{
	t_mvl	*tmp;

	tmp = begin;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->move = ft_strdup(str);
	tmp->next = init_listm();
	return (begin);
}

void	ra_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves)
{
	int		swap;
	int		i;

	if (data->len_b)
		i = tab_b[0];
	i = 0;
	if (!data->len_a)
		return ;
	swap = tab_a[0];
	while (i < data->len_a - 1)
	{
		tab_a[i] = tab_a[i + 1];
		i++;
	}
	tab_a[i] = swap;
	moves = save_and_add(moves, "ra\0");
}
