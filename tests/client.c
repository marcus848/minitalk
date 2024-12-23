/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 23:11:21 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/23 00:59:11 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	print_bit(int pid, char *str)
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
		}
		str++;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	pid = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		print_bit(pid, av[2]);
	}
}
