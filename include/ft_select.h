/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:14:09 by mallard           #+#    #+#             */
/*   Updated: 2017/11/04 18:37:21 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <sys/ioctl.h>
# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <termios.h>
# include <term.h>
# include <signal.h>
#include <stdio.h>


typedef struct	s_size
{
	int				term_size;
	int				len_max;
	int				nb_col;
}				t_size;

typedef struct	s_arg
{
	char			*name;
	int				status;
	struct s_arg	*next;
	struct s_arg	*prev;
}				t_arg;

typedef struct	s_all
{
	t_size			size;
	t_arg			*lst;
}				t_all;

t_all				all;
void			print_space(char *str, int size, int free, int color);
void			putstr_color(char *str, int i);
t_size			ini_size(int size_max);
int				max_size(char **t);
void			char_del(char **t, int i, int free);
int				voir_touche(t_arg *lst, t_size size);
t_arg			*arg_new(char *name, int status);
void			arg_chr(t_arg *lst, t_arg **origin);
void			arg_add(t_arg **lst, t_arg *new);
t_arg			*arg_ini(void);
t_arg			*arg_set(char **t);
void			print_lst(t_arg *lst, t_size size);
void			ft_right_left(t_arg *lst, t_size size, int i);
void			ft_bottom_top(t_arg *lst, t_size size, int i);
void			ft_space(t_arg *lst, t_size size);
void			arg_lst(t_arg *lst);
void			print_arg(t_list *lst);
void			print_signal(int mysignal);
void			ft_signal(void);
void			ft_quit(int mysignal);

#endif
