/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerparse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:23:22 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:23:23 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int		*get_num(int len, char **str)
{
	int		i;
	int		*tab;

	i = 0;
	tab = (int*)ft_memalloc(sizeof(int) * len + 1);
	while (i < len)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	i--;
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (tab);
}

int		get_tab_len(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

t_lst	*init_list(void)
{
	t_lst *new;

	new = (t_lst*)ft_memalloc((sizeof(t_lst)));
	new->next = NULL;
	new->move = NULL;
	return (new);
}

t_lst	*get_moves(void)
{
	char	*instruction;
	int		ret;
	t_lst	*tmp;
	t_lst	*begin;

	begin = init_list();
	tmp = begin;
	ret = 1;
	while (ret)
	{
		instruction = NULL;
		ret = get_next_line(0, &instruction);
		if (ret <= 0 || ft_strcmp("", instruction) == 0)
		{
			if (instruction != NULL)
				free(instruction);
			break ;
		}
		tmp->move = ft_strdup(instruction);
		free(instruction);
		tmp->next = init_list();
		tmp = tmp->next;
	}
	return (begin);
}

int		is_larger_max_int(char *str)
{
	int			index;
	long int	number;
	int			numsign;

	numsign = 1;
	number = 0;
	index = 0;
	while (str[index] != '\0' && str[index] <= 32 && str[index] != '\200')
		index++;
	if (str[index] == '-')
	{
		numsign = -1;
		index++;
	}
	else if (str[index] == '+')
		index++;
	while (str[index] >= '0' && str[index] <= '9')
	{
		number *= 10;
		number += str[index] - '0';
		index++;
	}
	if (number > 2147483647 || number < -2147483648)
		return (1);
	return (0);
}
