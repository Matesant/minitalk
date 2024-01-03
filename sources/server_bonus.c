/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:03:30 by matesant          #+#    #+#             */
/*   Updated: 2024/01/03 14:38:21 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	bytes;
	static int	bits;

	bytes = 0;
	bits = 0;
	context = NULL;
	if (signal == SIGUSR1)
		bytes += 0 << bits;
	else if (signal == SIGUSR2)
		bytes += 1 << bits;
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", bytes);
		bits = 0;
		bytes = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = handler;
	sigact.sa_flags = SA_SIGINFO;
	sigemptyset(&sigact.sa_mask);
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	ft_printf("PID:%d\n", getpid());
	while (1)
	{
		pause();
	}
}
