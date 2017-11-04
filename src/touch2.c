/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:31:57 by mallard           #+#    #+#             */
/*   Updated: 2017/11/02 17:45:36 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_right_left(t_arg *lst, t_size size, int i)
{
	t_arg		*tmp;

	tmp = lst;
	while (tmp->status != 1 && tmp->status != 3)
		tmp = tmp->next;
	tmp->status--;
	tmp = (i == 1) ? tmp->next : tmp->prev;
	if (tmp->status == -1)
		tmp = (i == 1) ? tmp->next : tmp->prev;
	tmp->status++;
	ft_putchar('\n');
	print_lst(lst, size);
}

void			ft_bottom_top(t_arg *lst, t_size size, int t)
{
	t_arg		*tmp;
	int			i;

	i = 0;
	tmp = lst;
	while (tmp->status != 1 && tmp->status != 3)
		tmp = tmp->next;
	tmp->status--;
	while (i < size.nb_col)
	{
		if (tmp->status != -1)
			i++;
		tmp = (t == 1) ? tmp->next : tmp->prev;
	}
	if (tmp->status == -1)
		tmp = (t == 1) ? tmp->next : tmp->prev;
	tmp->status++;
	ft_putchar('\n');
	print_lst(lst, size);
}

void			ft_space(t_arg *lst, t_size size)
{
	t_arg		*tmp;

	tmp = lst;
	while (tmp->status != 1 && tmp->status != 3)
		tmp = tmp->next;
	if (tmp->status == 1)
		tmp->status += 2;
	else if (tmp->status == 3)
		tmp->status -= 2;
	ft_right_left(lst, size, 1);
}
