/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-hach <rel-hach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 10:54:31 by rel-hach          #+#    #+#             */
/*   Updated: 2022/05/17 12:14:49 by rel-hach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define ZERO SIGUSR2 
# define ONE SIGUSR1
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>

typedef struct s_var
{
	int		i;
	int		pid;
	int		bit;
	int		count;
	char	c;
	char	*str;
	int		index;
	int		nb_bytes;
}	t_var;

void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_create_string(t_var *v, pid_t pid);
void	ft_bzero(t_var *s, size_t n);
int		determine_category(char c);

#endif
