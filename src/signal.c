/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 15:46:35 by mallard           #+#    #+#             */
/*   Updated: 2017/11/04 21:09:10 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		ft_signal(void)
{
	signal(SIGWINCH, print_signal);
	signal(SIGINT, SIG_IGN); // interruption
	signal(SIGQUIT, SIG_IGN); // instruction QUIT
	signal(SIGTSTP, SIG_IGN); // demande suspention clavier
	signal(SIGTTIN, SIG_IGN); // lecture arriere terminal
	signal(SIGTTOU, SIG_IGN); // ecriture arriere terminal
	signal(SIGCHLD, SIG_IGN); // modification status fils ????
}

void        ft_quit(int mysignal)
{
	printf("je quitte\n");
	exit(1);
}

void		print_signal(int mysignal)
{
	extern t_all	all;

	all.size = ini_size(all.size.len_max);
	if (all.size.nb_col > 0)
	{
		ft_putchar('\n');
		print_lst(all.lst, all.size);
	}
	else
		ft_putendl("je suis en pls");
}
