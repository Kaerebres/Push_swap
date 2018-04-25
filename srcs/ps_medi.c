/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_medi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 14:38:28 by csimon            #+#    #+#             */
/*   Updated: 2017/10/21 14:38:29 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ps.h"

void	swap_stuff(int *tab, int i, int j)
{
	int		swp;

	swp = tab[i];
	tab[i] = tab[j];
	tab[j] = swp;
}

int		*init_tab(int *tab, int len)
{
	int		i;
	int		*tab2;

	tab2 = NULL;
	i = 0;
	tab2 = (int*)ft_memalloc(sizeof(int) * (len + 1));
	if (tab2 == NULL)
		ft_printf("MEMORYFAIL");
	while (i < len)
	{
		tab2[i] = tab[i];
		i++;
	}
	return (tab2);
}

void	quick_sort(int *tab, int low, int high)
{
	int		i;
	int		j;
	int		pivot;

	i = 0;
	j = 0;
	pivot = 0;
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while ((tab[i] <= tab[pivot]) && (i < high))
				i++;
			while (tab[j] > tab[pivot])
				j--;
			if (i < j)
				swap_stuff(tab, i, j);
		}
		swap_stuff(tab, pivot, j);
		quick_sort(tab, low, j - 1);
		quick_sort(tab, j + 1, high);
	}
}

int		rand_medi(int *tab2, int high)
{
	int		i;

	if (high < 150)
		i = tab2[(high / 4 + high % 4) % (high - 1)];
	else
		i = tab2[(high / 7 + high % 7) % (high - 1)];
	free(tab2);
	return (i);
}

int		quick_medi(int *tab, int low, int high)
{
	int		*tab2;
	int		j;
	int		i;
	int		pivot;

	tab2 = init_tab(tab, high);
	if (low < high)
	{
		pivot = low;
		i = low;
		j = high;
		while (i < j)
		{
			while ((tab2[i] <= tab2[pivot]) && (i < high))
				i++;
			while (tab2[j] > tab2[pivot])
				j--;
			if (i < j)
				swap_stuff(tab2, i, j);
		}
		swap_stuff(tab2, pivot, j);
		quick_sort(tab2, low, j - 1);
		quick_sort(tab2, j + 1, high);
	}
	return (rand_medi(tab2, high));
}
