/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csimon <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 10:16:08 by csimon            #+#    #+#             */
/*   Updated: 2017/10/04 10:16:10 by csimon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H
# include "libftprintf/src/ft_printf.h"
# include "libftprintf/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_mlist
{
	char			*move;
	struct s_mlist	*next;
}				t_mvl;

typedef struct	s_lens
{
	int len_a;
	int len_b;
	int median;
}				t_lens;

int				quick_medi(int *tab, int low, int high);
void			print_tab(int *tab, int len);
t_mvl			*save_and_add(t_mvl *begin, char *str);
void			sort_all_a(int *tab_a, int *tab_b, t_lens *data, t_mvl *moves);
void			sort_a(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			sort_med(int *tab_a, int *tab_b, t_lens *data, t_mvl *move);
void			quick_sort(int *tab, int low, int high);
t_mvl			*init_listm(void);
void			sa_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			sb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			pa_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			pb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			ra_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			rb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			rr_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			rra_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			rrb_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			rrr_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			ss_move(int *tab_a, int *tab_b, t_lens *data, t_mvl *tmp);
void			ft_mvlstdel(t_mvl **alst);
int				get_tab_len(char **str);
t_mvl			*init_listm(void);
void			print_instructions(t_mvl *begin);
void			solve_sort(int *tab_a, int len_a);

#endif
