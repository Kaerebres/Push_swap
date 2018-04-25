/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:31:36 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:31:38 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void			print_tab(int *tab, int len)
{
	int		i;

	i = 0;
	ft_printf("Sorted tab:\n");
	while (i < len)
	{
		ft_printf("%d ", tab[i]);
		i++;
	}
	ft_printf("\n");
}

void			ft_pslstdel(t_lst **alst)
{
	t_lst	*tmp;
	t_lst	*buf;

	tmp = *alst;
	if (tmp != NULL)
	{
		while (tmp != NULL)
		{
			free(tmp->move);
			buf = tmp;
			tmp = tmp->next;
			free(buf);
		}
	}
	*alst = NULL;
}

int				free_lst_tab(int *tab_b, t_lst *begin, int ret)
{
	free(tab_b);
	ft_pslstdel(&begin);
	return (ret);
}

const t_mvlist	*mv_tab_slg(void)
{
	static const t_mvlist gmv_tab[12] = {{&sa_move, "sa"}, {&sb_move, "sb"},
	{&ss_move, "ss"}, {&pa_move, "pa"}, {&pb_move, "pb"}, {&ra_move, "ra"},
	{&rb_move, "rb"}, {&rr_move, "rr"}, {&rra_move, "rra"},
	{&rrb_move, "rrb"}, {&rrr_move, "rrr"}, {NULL, NULL}};

	return (gmv_tab);
}

int				solve_sort(int *tab_a, int len_a, t_lst *moves)
{
	int				*tab_b;
	int				len_b;
	int				i;
	t_lst			*begin;
	const t_mvlist	*mv_t;

	mv_t = mv_tab_slg();
	begin = moves;
	i = 0;
	tab_b = (int*)ft_memalloc(sizeof(int) * (len_a + 1));
	len_b = 0;
	while (moves != NULL && moves->move != NULL)
	{
		while (mv_t[i].code != NULL && ft_strcmp(mv_t[i].code, moves->move))
			i++;
		if (mv_t[i].code == NULL && moves->move != NULL)
			return (free_lst_tab(tab_b, begin, -1));
		mv_t[i].ptr(tab_a, tab_b, &len_a, &len_b);
		i = 0;
		moves = moves->next;
	}
	free_lst_tab(tab_b, begin, 0);
	if (is_sorted(tab_a, len_a, &len_b) != 0)
		return (1);
	return (0);
}
