/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 13:38:17 by mallard           #+#    #+#             */
/*   Updated: 2017/11/04 19:49:42 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			arg_lst(t_arg *lst)
{
	t_list		*arg;
	t_list		*new;

	arg_chr(lst, &lst);
	lst = lst->next;
	arg = NULL;
	while (lst->status != -1)
	{
		if (lst->status == 2 || lst->status == 3)
		{
			if (arg == NULL)
				arg = ft_lstnew(lst->name, ft_strlen(lst->name));
			else
			{
				new = ft_lstnew(lst->name, ft_strlen(lst->name) + 1);
				ft_lstaddend(&arg, new);
			}
		}
		lst = lst->next;
	}
	ft_putchar('\n');
	print_arg(arg);
}

void			print_arg(t_list *lst)
{
	while (lst)
	{
		ft_putstr(lst->content);
		if (lst->next)
			ft_putchar(' ');
		lst = lst->next;
	}
}

int				voir_touche(t_arg *lst, t_size size)
{
	char		buff[3];
	struct sigaction	*act;
	struct sigaction	*oldact;

	while (42)
	{
		ft_signal();
		read(0, buff, 3);
		if (buff[0] == 27)
		{
			if (buff[2] == 65)
				ft_bottom_top(lst, size, 0);
			else if (buff[2] == 66)
				ft_bottom_top(lst, size, 1);
			else if (buff[2] == 67)
				ft_right_left(lst, size, 1);
			else if (buff[2] == 68)
				ft_right_left(lst, size, 0);
		}
		else if (buff[0] == 32)
			ft_space(lst, size);
		else if (buff[0] == 10)
		{
			arg_lst(lst);
			return (0);
		}
	}
	return (0);
}
