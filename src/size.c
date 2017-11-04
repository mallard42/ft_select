/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 05:01:25 by mallard           #+#    #+#             */
/*   Updated: 2017/11/02 17:42:37 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_size		ini_size(int size_max)
{
	struct winsize	w;
	t_size			size;

	ioctl(0, TIOCGWINSZ, &w);
	size.term_size = w.ws_col;
	size.len_max = size_max;
	size.nb_col = size.term_size / (size.len_max + 2);
	return (size);
}

int			max_size(char **t)
{
	int		i;
	int		max;

	i = 0;
	max = 0;
	while (t[i])
	{
		if (ft_strlen(t[i]) > max)
			max = ft_strlen(t[i]);
		i++;
	}
	return (max);
}

void		char_del(char **t, int i, int free)
{
	int				size;
	char			*tmp;

	size = ft_tablen(t);
	tmp = t[i];
	if (free == 1)
		ft_strdel(&tmp);
	while (i < size)
	{
		t[i] = t[i + 1];
		i++;
	}
}
