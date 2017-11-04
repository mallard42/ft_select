/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 02:54:27 by mallard           #+#    #+#             */
/*   Updated: 2017/11/02 17:41:47 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		putstr_color(char *str, int i)
{
	if (i == 1)
		ft_putstr("\e[4m");
	else if (i == 2)
		ft_putstr("\e[1;30;107m");
	else if (i == 3)
		ft_putstr("\e[4;30;107m");
	ft_putstr(str);
	ft_putstr("\e[0m");
}

void		print_lst(t_arg *lst, t_size size)
{
	t_arg		*tmp;
	int			i;

	i = 0;
	tmp = lst->next;
	while (tmp->status != -1)
	{
		print_space(tmp->name, size.len_max + 1, 0, tmp->status);
		if ((i + 1) % size.nb_col == 0)
			ft_putchar('\n');
		tmp = tmp->next;
		i++;
	}
}

void		print_space(char *str, int size, int free, int color)
{
	int				i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		putstr_color(str, color);
		while (i < size)
		{
			ft_putchar(' ');
			i++;
		}
		if (free == 1)
			ft_strdel(&str);
	}
}
