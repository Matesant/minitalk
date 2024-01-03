/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:05:10 by matesant          #+#    #+#             */
/*   Updated: 2024/01/03 12:16:21 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <signal.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int		g_count = 0;

void	handler(int sig)
{
	printf("CAPTADO PATRAO APERTA DENOVO AE");
}

int	main(int ac, char **av)
{
	signal(SIGINT, handler);
	while (1)
	{
		pause();
	}
	return (0);
}
