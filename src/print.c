/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:54:27 by mallard           #+#    #+#             */
/*   Updated: 2017/06/30 07:36:38 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		putstr_color(char *str)
{
	ft_putstr("\e[4m");
	ft_putstr(str);
	ft_putstr("\e[0m");
}

void		print_tab_p(char **t, int pos)
{
	int		i;
	t_size	size;

	size = ini_size(max_size(t));
	i = 0;
	if (size.nb_col == 0)
		ft_putendl("windows is too small");
	else
	{
		while (t[i])
		{
			if (i == pos)
				print_space(t[i], size.len_max + 1, 0, 1);
			else
				print_space(t[i], size.len_max + 1, 0, 0);
			if ((i + 1) % size.nb_col == 0)
				ft_putchar('\n');
			i++;
		}
		ft_putchar('\n');
	}
}

void        print_space(char *str, int size, int free, int color)
{
	int             i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		if (color == 1)
			putstr_color(str);
		else
			ft_putstr(str);
		while (i < size)
		{
			ft_putchar(' ');
			i++;
		}
		if (free == 1)
			ft_strdel(&str);
	}
}
