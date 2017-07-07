/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 20:14:09 by mallard           #+#    #+#             */
/*   Updated: 2017/06/29 22:37:05 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
#define FT_SELECT_H

#include <sys/ioctl.h>
#include "../libft/include/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <term.h>

typedef struct	s_size
{
	int		term_size;
	int		len_max;
	int		nb_col;
}				t_size;

void		print_space(char *str, int size, int free, int color);
void		putstr_color(char *str);
void		ft_clean(void);
void		print_tab_p(char **t, int pos);
t_size		ini_size(int size_max);
int			max_size(char **t);
void		char_del(char **t, int i, int free);

#endif
