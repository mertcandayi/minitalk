/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:42:18 by medayi            #+#    #+#             */
/*   Updated: 2025/02/27 00:01:50 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

volatile sig_atomic_t	g_sig = 0;

static void	ft_handler(int x)
{
	if (x == SIGUSR1)
		g_sig = 1;
	else
		exit(EXIT_FAILURE);
}

static int	ft_atoi(char *str)
{
	int	res;
	int	i;

	i = 1;
	res = 0;
	while (*str <= 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			i *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - '0';
		str++;
	}
	return (res * i);
}

static void	ft_sendbit(int pid, unsigned char *str)
{
	int	i;

	while (*str)
	{
		i = 7;
		while (i >= 0)
		{
			g_sig = 0;
			if ((*str >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			while (g_sig == 0)
				pause();
			i--;
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		ft_printf("%s [PID] [MESSAGE]\n", av[0]);
		return (-1);
	}
	pid = ft_atoi(av[1]);
	if (pid == -1 || pid > 4194304 || kill(pid, 0) == -1)
	{
		ft_printf("wrong pid!!!! haha loser :)");
		return (-1);
	}
	signal(SIGUSR1, ft_handler);
	ft_sendbit(pid, (unsigned char *)av[2]);
	return (0);
}
