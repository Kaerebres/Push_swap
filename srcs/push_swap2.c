/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:31:11 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:31:15 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	ft_mvlstdel(t_mvl **alst)
{
	t_mvl	*tmp;
	t_mvl	*buf;

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

int		get_tab_len(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

t_mvl	*init_listm(void)
{
	t_mvl	*new;

	new = (t_mvl*)ft_memalloc(sizeof(t_mvl));
	new->move = NULL;
	new->next = NULL;
	return (new);
}

void	print_instructions(t_mvl *begin)
{
	t_mvl	*tmp;
	int		i;

	i = 0;
	tmp = begin;
	if (begin == NULL)
		return ;
	while (tmp != NULL)
	{
		i++;
		if (tmp->next != NULL)
			ft_printf("%s\n", tmp->move);
		tmp = tmp->next;
	}
}

void	solve_sort(int *tab_a, int len_a)
{
	t_mvl	*tmp;
	int		*tab_b;
	t_lens	*data;
	int		trulen;
	t_mvl	*begin;

	trulen = len_a;
	if (len_a <= 1)
		return ;
	data = ft_memalloc(sizeof(t_lens));
	data->len_a = len_a;
	data->len_b = 0;
	tab_b = (int*)ft_memalloc(sizeof(int) * (len_a + 1));
	begin = init_listm();
	tmp = begin;
	sort_all_a(tab_a, tab_b, data, tmp);
	print_instructions(begin);
	free(tab_b);
	free(data);
	ft_mvlstdel(&begin);
}
