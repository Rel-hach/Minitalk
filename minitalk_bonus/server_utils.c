/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:05:30 by rel-hach          #+#    #+#             */
/*   Updated: 2022/05/17 12:09:43 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;
	int				i;

	nb = (unsigned int)n;
	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -n;
	}
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd(nb + '0', fd);
	}
	if (nb > 9)
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}

void	ft_bzero(t_var *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (s->str)
	{
		free(s->str);
		s->str = NULL;
	}
	str = (char *)s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

int	determine_category(char c)
{
	int	i;
	int	count;

	if (((c >> 7) & 1) == 0)
		return (1);
	i = 6;
	count = 1;
	while (((c >> i) & 1) != 0 && i >= 0)
	{
		count++;
		i--;
	}
	return (count);
}

void	ft_create_string(t_var *v, pid_t pid)
{
	if (v->c == '\0')
		kill(pid, ONE);
	v->nb_bytes = determine_category(v->c);
	v->str = malloc(sizeof(char) * v->nb_bytes + 1);
	if (v->str == NULL)
		exit(1);
}
