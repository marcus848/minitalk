/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:47:16 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/26 17:46:06 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_wait_response = 0;

void	handle_response(int signal)
{
	if (signal == SIGUSR2)
		ft_printf(BLUE_I "⭐⭐⭐ %sMessage received%s ⭐⭐⭐\n", BLUE_B, RESET);
	g_wait_response = 1;
}

void	send_bits(int pid, char *str)
{
	static int	bit;

	while (*str)
	{
		bit = 8;
		while (bit--)
		{
			g_wait_response = 0;
			if ((*str >> bit) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			while (!g_wait_response)
				;
		}
		str++;
	}
	bit = 8;
	while (bit--)
	{
		g_wait_response = 0;
		kill(pid, SIGUSR1);
		while (!g_wait_response)
			;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	signal(SIGUSR1, handle_response);
	signal(SIGUSR2, handle_response);
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		send_bits(pid, av[2]);
	}
	else
	{
		ft_printf(RED_B "Sintax error:\n" RESET);
		ft_printf("Only accept this: ");
		ft_printf(YELLOW_U "./client <pid> <message>\n" RESET);
	}
}
