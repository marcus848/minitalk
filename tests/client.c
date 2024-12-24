/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:11:21 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/23 23:59:13 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

static int	g_wait_server = 0;

void	update_wait_server(int signal)
{
	(void)signal;
	if (signal == SIGUSR2)
		ft_printf("%sSuccess:%s Message received\n", GREEN, RESET);
	g_wait_server = 1;
}

void	send_bit(int pid, char *str)
{
	static int	bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_wait_server)
				;
			g_wait_server = 0;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		kill(pid, SIGUSR1);
		while (!g_wait_server)
			;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = 0;
	signal(SIGUSR1, update_wait_server);
	signal(SIGUSR2, update_wait_server);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bit(pid, av[2]);
	}
	else
	{
		ft_printf(RED "Sintax error\n" RESET);
		ft_printf("Only accept this: ./client <PID> <MESSAGE>\n");
	}
	return (0);
}
