/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:31:44 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:31:45 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		is_sorted(int *tab_a, int len_a, int *len_b)
{
	int		index;

	index = 0;
	if ((*len_b) != 0)
		return (0);
	while (index < len_a - 1)
	{
		if (tab_a[index] > tab_a[index + 1])
			return (0);
		index++;
	}
	return (1);
}

int		*get_numbers(int argc, char **argv, int *len)
{
	int		*tab;
	int		size;

	size = 1;
	while (size < argc - 1 && argv[size][0] >= '0' && argv[size][0] <= '9')
		size++;
	tab = (int*)ft_memalloc((sizeof(int) * size));
	*len = size;
	size = 0;
	while (size < *len)
	{
		tab[size] = ft_atoi(argv[size + 1]);
		size++;
	}
	return (tab);
}

int		is_error(int argc, char **argv, int startcode)
{
	int		index;
	int		cursor;

	index = startcode;
	while (index < argc)
	{
		cursor = 0;
		while (argv[index][cursor] != '\0')
		{
			if (((argv[index][cursor] < '0' || argv[index][cursor] > '9')
				&& argv[index][cursor] != '-' && argv[index][cursor] != '+')
				|| is_larger_max_int(argv[index]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			cursor++;
		}
		index++;
	}
	return (0);
}
