/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:22:33 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/05/23 23:56:03 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "mini_talk.h"
#include <signal.h>
#include <stdio.h>

void	print_pid(int n)
{
	ft_printf("\n─────────────***{^_^}***─────────────\n");
	ft_printf("\n\n     >-- my_pid: %d --<    \n\n", n);
	ft_printf("\n─────────────***{^_^}***─────────────\n");
}

void	sig_handler(int sig, siginfo_t *my_struct, void *nothing)
{
	static int		i = 7;
	static char		c;
	static pid_t	client_pid;

	(void)nothing;
	if (my_struct->si_pid != client_pid)
	{
		client_pid = my_struct->si_pid;
		i = 7;
		c = 0;
	}
	if (sig == SIGUSR2)
		c += 1 << i;
	i--;
	if (i == -1)
	{
		ft_printf("%c", c);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	my_struct;

	print_pid(getpid());
	while (1)
	{
		my_struct.sa_sigaction = sig_handler;
		my_struct.sa_flags = SA_SIGINFO;
		protect(sigaction(SIGUSR1, &my_struct, NULL));
		protect(sigaction(SIGUSR2, &my_struct, NULL));
		usleep(500);
	}
	return (0);
}
