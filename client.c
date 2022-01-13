/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:35:53 by yachehbo          #+#    #+#             */
/*   Updated: 2022/01/11 19:47:53 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bits(char *tab, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (tab[i] == '1')
			kill(pid, SIGUSR1);
		else if (tab[i] == '0')
			kill(pid, SIGUSR2);
		usleep(700);
		i++;
	}
	free (tab);
}

void	ft_send(int pid)
{
	int	i;

	i = 0;
	ft_printf("SEND !\n");
	while (i < 8)
	{
		kill(pid, SIGUSR2);
		usleep(200);
		i++;
	}
}

void	convert_to_bits(unsigned char c, int pid)
{
	int		i;
	int		a;
	char	*tab;

	a = 128;
	i = 0;
	tab = (char *)malloc(9);
	if (!tab)
		return ;
	while (a > 0 && i < 8)
	{
		if (c >= a)
		{
			tab[i++] = '1';
			c %= a;
			a /= 2;
		}
		else
		{
			tab[i++] = '0';
			a /= 2;
		}
	}
	tab[i] = '\0';
	send_bits(tab, pid);
}

void	handler(int sing)
{
	if (sing == SIGUSR1)
		ft_printf("RECEIVED !\n");
}

int	main(int ac, char **av)
{
	int	e;
	int	pid;
	int	i;

	i = -1;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid == -1)
			ft_printf("Bad PID\n");
		e = kill(pid, 0);
		if (e == -1)
			ft_printf("Bad PID\n");
		signal(SIGUSR1, handler);
		while (av[2][++i])
		{
			convert_to_bits(av[2][i], pid);
			usleep(100);
		}
		if (av[2][i] == '\0' && e != -1)
			ft_send(pid);
	}
	return (0);
}
