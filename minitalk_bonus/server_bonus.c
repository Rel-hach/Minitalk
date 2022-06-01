/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 00:44:25 by rel-hach          #+#    #+#             */
/*   Updated: 2022/05/17 12:12:14 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write (fd, &s[i], 1);
			i++;
		}
	}
}

static void	intialize(t_var *v)
{
	v->i = 0;
	v->c = 0;
}

static void	ft_signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	static t_var	v;

	(void)ucontext;
	if (v.pid != info->si_pid)
		ft_bzero(&v, sizeof(t_var));
	v.pid = info->si_pid;
	if (sig == ONE)
		v.bit = 1;
	else if (sig == ZERO)
		v.bit = 0;
	v.c = v.c + (v.bit << v.i);
	v.i++;
	if (v.i == 8)
	{
		if (v.count == 0)
			ft_create_string(&v, v.pid);
		v.str[v.count++] = v.c;
		if (v.count == v.nb_bytes)
		{
			v.str[v.count] = '\0';
			ft_putstr_fd(v.str, 1);
			ft_bzero(&v, sizeof(t_var));
		}
		intialize(&v);
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	pid = getpid();
	ft_putstr_fd("Process ID is : ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = ft_signal_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
}
