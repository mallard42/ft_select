/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 16:46:06 by mallard           #+#    #+#             */
/*   Updated: 2017/11/02 17:44:25 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_arg		*arg_new(char *name, int status)
{
	t_arg	*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		exit(1);
	new->name = ft_strdup(name);
	new->status = status;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		arg_chr(t_arg *lst, t_arg **origin)
{
	t_arg		*tmp;

	if (lst)
	{
		tmp = lst;
		while (tmp->status != -1)
			tmp = tmp->next;
		*origin = tmp;
	}
}

void		arg_add(t_arg **lst, t_arg *new)
{
	t_arg		*tmp;
	t_arg		*t;

	if (*lst)
	{
		tmp = *lst;
		t = (*lst)->next;
		if (t != NULL)
			while (t->status != -1)
			{
				t = t->next;
				tmp = tmp->next;
			}
		if (t != NULL)
			t = tmp;
		tmp->next = new;
		arg_chr(*lst, &t);
		t->prev = new;
		new->next = t;
		new->prev = tmp;
	}
}

t_arg		*arg_ini(void)
{
	t_arg		*tmp;

	tmp = arg_new("first", -1);
	return (tmp);
}

t_arg		*arg_set(char **t)
{
	t_arg		*new;
	t_arg		*lst;
	int			i;

	i = -1;
	lst = arg_ini();
	while (t[++i])
	{
		new = arg_new(t[i], (i == 0) ? 1 : 0);
		arg_add(&lst, new);
	}
	return (lst);
}
