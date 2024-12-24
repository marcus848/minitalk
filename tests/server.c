/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcudos <marcudos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 00:36:41 by marcudos          #+#    #+#             */
/*   Updated: 2024/12/24 00:09:21 by marcudos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/libft.h"

void	message_completed(char **str, int *bit_c, unsigned char *c)
{
	ft_printf("%s\n", *str);
	free(*str);
	*str = NULL;
	*bit_c = 0;
	*c = 0;
}

void	print_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static char				*str = NULL;
	static int				bit_count = 0;

	(void)context;
	c <<= 1;
	if (signal == SIGUSR2)
		c |= 1;
	bit_count++;
	if (!str)
		str = ft_strdup("");
	if (bit_count == 8)
	{
		if (c == 0)
		{
			message_completed(&str, &bit_count, &c);
			kill(info->si_pid, SIGUSR2);
			return ;
		}
		else
			str = ft_strjoin(str, (char []){c, '\0'});
		bit_count = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = print_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("Hello started a test. my pid is: %d\n", pid);
	while (1)
		pause();
	return (0);
}
