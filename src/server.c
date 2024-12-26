/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:08:46 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/26 17:46:11 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	char_completed(char **str, char *c, int *bit_c, siginfo_t *info)
{
	char	*temp;

	if (*c == 0)
	{
		ft_printf("%s\n", *str);
		free(*str);
		*c = 0;
		*bit_c = 0;
		*str = NULL;
		kill(info->si_pid, SIGUSR2);
		return (0);
	}
	temp = ft_strjoin(*str, c);
	free(*str);
	*str = temp;
	*c = 0;
	*bit_c = 0;
	return (1);
}

void	print_signal(int signal, siginfo_t *info, void *context)
{
	static char		c = 0;
	static char		*str = NULL;
	static int		bit_count = 0;

	context = NULL;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	if (!str)
		str = ft_strdup("");
	bit_count++;
	if (bit_count == 8)
	{
		if (!char_completed(&str, &c, &bit_count, info))
			return ;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf(GREEN_B "Hello, let's start. My pid is: %d\n" RESET, getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = print_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}
