/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:01:27 by rel-hach          #+#    #+#             */
/*   Updated: 2022/05/17 12:23:41 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

static int	ft_atoi(const char	*str)
{
	int		i;
	int		j;
	int		sign;
	int		n;

	i = 0;
	j = 0;
	sign = 1;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}

static void	ft_send_message(char c, pid_t process_id)
{
	int	mask;
	int	i;

	mask = 1;
	i = 7;
	while (i >= 0)
	{
		if (c & mask)
			kill(process_id, SIGUSR1);
		else
			kill(process_id, SIGUSR2);
		usleep(800);
		i--;
		mask = mask << 1;
	}
}

int	main(int ac, char **av)
{
	pid_t				process_id;
	int					i;

	if (ac != 3)
	{
		ft_putstr_fd("Number of Arguments is invalid\n", STDERR_FILENO);
		exit(1);
	}
	i = 0;
	process_id = ft_atoi(av[1]);
	if (process_id < 0)
		return (write(2, "PID does not exit", 17));
	while (av[2][i])
	{
		ft_send_message(av[2][i], process_id);
		i++;
	}
	return (0);
}
