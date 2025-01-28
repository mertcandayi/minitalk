/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
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
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac != 3)
    {
        printf("%s [PID] [SIGNAL]\n", av[0]);
        return (1);
    }
    kill(atoi(av[1]),(int)av[2]);
}