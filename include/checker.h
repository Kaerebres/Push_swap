/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:16:21 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:16:23 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libftprintf/src/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_mlst
{
	struct s_mlst	*next;
	char			*move;
}				t_lst;

typedef struct	s_move_list
{
	void	(*ptr)(int *tab_a, int *tab_b, int *len_a, int *len_b);
	char	*code;
}				t_mvlist;

void			sa_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			sb_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			pa_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			pb_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			ra_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			rb_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			rr_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			rra_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			rrb_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			rrr_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
void			ss_move(int *tab_a, int *tab_b, int *len_a, int *len_b);
t_lst			*init_list();
t_lst			*get_moves();
int				*get_numbers(int argc, char **argv, int *len);
int				is_error(int argc, char **argv, int startcode);
int				get_tab_len(char **str);
int				*get_num(int len, char **str);
int				is_sorted(int *tab_a, int len_a, int *len_b);
void			print_tab(int *tab, int len);
void			ft_pslstdel(t_lst **alst);
int				is_sorted(int *tab_a, int len_a, int *len_b);
void			print_tab(int *tab, int len);
void			ft_pslstdel(t_lst **alst);
int				free_lst_tab(int *tab_b, t_lst *begin, int ret);
int				solve_sort(int *tab_a, int len_a, t_lst *moves);
int				is_larger_max_int(char *str);

#endif
