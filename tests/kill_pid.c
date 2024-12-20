#include <signal.h>
#include <unistd.h>
#include "../libft/include/libft.h"

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		pid_t pid = ft_atoi(av[1]);
		
		ft_printf("matando o pid");
		kill(pid, SIGINT);
	}
	ft_printf("\n");
}
