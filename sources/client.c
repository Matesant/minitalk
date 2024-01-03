/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:05:12 by matesant          #+#    #+#             */
/*   Updated: 2024/01/03 13:20:53 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(unsigned char message, int pid);

int	main(int argc, char **argv)
{
	char	*message;
	int		pid;

	if (argc == 3)
	{
		pid = atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			send_signal(*message, pid);
			message++;
		}
	}
}

void	send_signal(unsigned char message, int pid)
{
	int	bits;

	bits = 0;
	while (bits < 8)
	{
		if (message >> bits & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR1);
		bits++;
	}
}
