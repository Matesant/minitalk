/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:05:12 by matesant          #+#    #+#             */
/*   Updated: 2024/01/03 11:53:09 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	send_signal(unsigned char message, int pid);

int	main(int argc, char **argv)
{
	char	*message;

	if (argc == 3)
	{
		argc = atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			send_signal(*message, argc);
			message++;
		}
	}
}

void	send_signal(unsigned char message, int pid)
{
	int	i;

	i = 8;
	while (i--)
	{
		if (message >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR1);
		usleep(1000000);
	}
}
