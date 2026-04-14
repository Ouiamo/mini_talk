/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oaoulad- <oaoulad-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 02:32:10 by oaoulad-          #+#    #+#             */
/*   Updated: 2024/05/24 01:02:45 by oaoulad-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

void	my_handler2(int sig)
{
	int	a;

	if (sig == SIGINT)
		a = 0;
}

void	print_client(void)
{
	ft_printf("───────────***{^_^}***───────────");
	ft_printf("\n\n         >--client--<        \n\n");
	ft_printf("───────────***{^_^}***───────────\n\n");
}

void	send_message(int pid, char byte)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (1 << i & byte);
		if (bit)
			protect(kill(pid, SIGUSR2));
		else
			protect(kill(pid, SIGUSR1));
		usleep(300);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	i;

	if (ac != 3 || my_atoi(av[1]) <= 0)
		exit(write(1, "there is an error\n", 18));
	i = -1;
	print_client();
	signal(SIGUSR2, success);
	while (av[2][++i])
		send_message(my_atoi(av[1]), av[2][i]);
	send_message(my_atoi(av[1]), '\0');
	return (0);
}
