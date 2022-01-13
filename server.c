/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachehbo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:41:27 by yachehbo          #+#    #+#             */
/*   Updated: 2022/01/11 19:39:24 by yachehbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_power(int nb, int power)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	while (i <= power)
	{
		result = result * nb;
		i++;
	}
	return (result);
}

struct	s_value
{
	int	character;
	int	num;
}s_value = {0, 7};

void	ft_handler(int sig, siginfo_t *info, void *empty)
{	
	static int	client_pid;

	(void)empty;
	if (client_pid != info->si_pid && s_value.num != 7)
	{
		s_value.num = 7;
		s_value.character = 0;
	}
	if (sig == SIGUSR1)
	{
		s_value.character += ft_power(2, s_value.num);
		s_value.num--;
	}
	else if (sig == SIGUSR2)
		s_value.num--;
	if (s_value.num == -1)
	{
		if (s_value.character == 0)
			kill(info->si_pid, SIGUSR1);
		else
			ft_printf("%c", s_value.character);
		s_value.num = 7;
		s_value.character = 0;
	}
	client_pid = info->si_pid;
}

int	main(void)
{
	int					pid;	
	struct sigaction	new;

	new.sa_sigaction = ft_handler;
	new.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("PID : %d\n", pid);
	sigaction(SIGUSR1, &new, NULL);
	sigaction(SIGUSR2, &new, NULL);
	while (1)
		pause();
	return (0);
}
