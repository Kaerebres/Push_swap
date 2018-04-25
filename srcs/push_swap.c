/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 15:27:46 by csimon            #+#    #+#             */
/*   Updated: 2017/10/20 15:27:48 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

int		*get_num(int argc, char **argv, int code)
{
	int		*tab;
	int		index;
	int		i;

	i = code;
	index = 0;
	tab = NULL;
	tab = (int*)ft_memalloc(sizeof(int) * (argc));
	while (i < argc)
	{
		tab[index] = ft_atoi(argv[i]);
		i++;
		index++;
	}
	return (tab);
}

int		is_error(int argc, char **argv, int startcode)
{
	int		index;
	int		cursor;

	cursor = 0;
	index = startcode;
	while (index < argc)
	{
		cursor = 0;
		while (argv[index][cursor] != '\0')
		{
			if (argv[index][cursor] < '0' || argv[index][cursor] > '9')
			{
				if (argv[index][cursor] != '-')
				{
					write(2, "Error\n", 6);
					return (1);
				}
			}
			cursor++;
		}
		index++;
	}
	return (0);
}

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
				return (1);
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

int		main(int argc, char **argv)
{
	int		*tab;
	char	**one_str;
	int		len;

	len = 0;
	if (argc == 2)
	{
		one_str = ft_strsplit(argv[1], ' ');
		len = get_tab_len(one_str);
		if (is_error(len, one_str, 0))
			return (free_str(one_str, len));
		tab = get_num(len, one_str, 0);
		free_str(one_str, len);
		solve_sort(tab, len);
	}
	else
	{
		if (is_error(argc, argv, 1))
			return (0);
		tab = get_num(argc, argv, 1);
		solve_sort(tab, argc - 1);
	}
	free(tab);
	return (0);
}
