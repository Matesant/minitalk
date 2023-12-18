/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:30 by matesant          #+#    #+#             */
/*   Updated: 2023/12/11 16:28:15 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void	handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "1", 1);
	else if (sig == SIGUSR2)
		write(1, "0", 1);
}

int	main(void)
{
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	printf("PID:%d\n", getpid());
	while (1)
	{
		pause();
	}
}