/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:05:12 by matesant          #+#    #+#             */
/*   Updated: 2024/01/04 11:50:16 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int		g_exit = 0;

void	handle(int signal)
{
	if (signal == SIGUSR1)
		g_exit = 1;
}

void	send_signal(unsigned char message, int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		g_exit = 0;
		if (message >> bits & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bits++;
		while (!g_exit)
			;
	}
}

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message = argv[2];
		signal(SIGUSR1, handle);
		signal(SIGUSR2, handle);
		while (*message)
		{
			send_signal(*message, pid);
			message++;
		}
		ft_printf("Message received by server\n");
	}
}
