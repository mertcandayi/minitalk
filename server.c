/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medayi    <medayi@student.42istanbul>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 22:11:44 by medayi            #+#    #+#             */
/*   Updated: 2025/01/27 22:11:44 by medayi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	handler(int x)
{
	printf("GELEN SINYAL NO: %i BINARY: %b\n", x, x);
	if(SIGUSR1 == x)
		printf("SIGUSER1 GELDU\n");
	if(SIGUSR2 == x)
		printf("SIGUSER2 GELDU\n");
	if(SIGTERM == x)
		printf("SIGTERM GELDU\n");
	if(2 == x)
		printf("kullanaman\n");
}

int	main(void)
{
	int pid;

	pid = getpid();
	printf("PID: %i\n", pid);
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	signal(SIGTERM, handler);
	signal(SIGINT, handler);
	while (1)
		pause();
}