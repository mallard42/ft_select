/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 22:48:03 by mallard           #+#    #+#             */
/*   Updated: 2017/06/25 23:04:44 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char    **ft_add_str_to_tab(char **tab, char *str, int free)
{
	char    **tmp;
	int     i;

	i = 0;
	if (!(tmp = ft_newtab(ft_tablen(tab) + 1)))
		return (NULL);
	while (tab[i] != NULL)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	if (free == 1)
		ft_tabdel(tab);
	tmp[i] = ft_strdup(str);
	return (tmp);
}
