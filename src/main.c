/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mallard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 14:13:44 by mallard           #+#    #+#             */
/*   Updated: 2017/07/04 07:10:25 by mallard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int		ft_ini(void)
{
	char            *name;
	struct termios  term;

	if (!(name = getenv("TERM")))
		return (0);
	if ((tgetent(NULL, name)) == 0)
		return (0);
	if (tcgetattr(0, &term))
		return (0);
	term.c_lflag &= ~(ICANON);
	//term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (0);
	return (1);
}

int		ft_exit(void)
{
	struct termios		term;

	if (tcgetattr(0, &term))
		return (0);
	term.c_lflag = (ICANON | ECHO);
	if (tcsetattr(0, 0, &term) == -1)
		return (0);
	return (1);
}

void	ft_clean(void)
{
	extern char		**environ;
	pid_t			f;

	f = fork();
	if (f > 0)
		wait(0);
	if (f == 0)
		execve("/usr/bin/clear", NULL, environ);
	if (f < 0)
		exit(EXIT_FAILURE);
}

int		main(int ac, char **av, char **env)
{
	char			*name;
	struct termios	term;

	if (ac > 1)
	{
		if (*env)
		{
			char_del(av, 0, 0);
			if ((ft_ini() == 0))
				return (-1);
			ft_clean();
			print_tab_p(av, 0);
			if (ft_exit() == 0)
				return (-1);
		}
		else
			ft_putendl("env is not enable");
	}
	else
		ft_putendl("Not enough agument");
	return (0);
}
