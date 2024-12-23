/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:36:41 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/23 00:44:03 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	print_signal(int signal)
{
	static unsigned char	c = 0;
	static int				bit_count = 0;

	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	bit_count++;
	if (bit_count == 8)
	{
		if (c == 0)
			ft_printf("\n");
		else
			ft_printf("%c", c);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Hello started a test. my pid is: %d\n", pid);
	signal(SIGUSR1, print_signal);
	signal(SIGUSR2, print_signal);
	while (1)
		pause();
}
