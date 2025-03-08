/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agedikog <gedikoglu_27@icloud.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 00:42:18 by medayi            #+#    #+#             */
/*   Updated: 2025/02/27 00:01:55 by agedikog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	ft_handler(int signum, siginfo_t *info, void *context)
{
	static int	i = 0;
	static int	c = 0;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	pid_t				pid;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = ft_handler;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1 || sigaction(SIGUSR2, &act,
			NULL) == -1)
	{
		ft_printf("kizilciklar oldu mu senelere doldu mu");
		return (-1);
	}
	pid = getpid();
	ft_printf("PID: %i\n", pid);
	while (1)
		pause();
	return (0);
}
