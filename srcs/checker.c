/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:15:21 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:15:36 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		is_double(int *tab, int len)
{
	int		i;
	int		j;
	int		save;

	i = 0;
	j = 1;
	while (i < len)
	{
		save = tab[i];
		while (j < len)
		{
			if (tab[j] == tab[i])
			{
				write(2, "Error\n", 6);
				return (1);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return (0);
}

int		free_str(char **str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (0);
}

int		free_tab(int *tab)
{
	free(tab);
	return (0);
}

void	deal_with_solve_ret(int ret)
{
	if (ret == 1)
		ft_printf("OK\n");
	else if (ret == 0)
		ft_printf("KO\n");
	else if (ret == -1)
		write(2, "Error\n", 6);
}

int		main(int argc, char **argv)
{
	int		*tab;
	int		len;
	t_lst	*moves;
	char	**one_str;

	if (argc == 1)
		return (0);
	if (argc != 2)
	{
		tab = get_numbers(argc, argv, &len);
		if (is_error(argc, argv, 1))
			return (free_tab(tab));
	}
	else
	{
		one_str = ft_strsplit(argv[1], ' ');
		len = get_tab_len(one_str);
		if (is_error(len, one_str, 0))
			return (free_str(one_str, len));
		tab = get_num(len, one_str);
	}
	if (is_double(tab, len) || !(moves = get_moves()))
		return (free_tab(tab));
	deal_with_solve_ret(solve_sort(tab, len, moves));
	return (free_tab(tab));
}
