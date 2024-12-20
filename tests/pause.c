#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/include/libft.h"

void handle_signal(int signo) {
	if (signo == SIGUSR1) {
		ft_printf("Recebido SIGUSR1! Retomando a execução.\n");
	}
}

int main() {
    // Configura o manipulador de sinal para SIGUSR1
	pid_t pid = getpid();

	ft_printf("my pid: %d\n", pid);
	signal(SIGUSR1, handle_signal);

	ft_printf("Aguardando o sinal SIGUSR1...\n");

	// Bloqueia até receber um sinal
	pause();

	ft_printf("Sinal recebido e tratado. Continuando o programa.\n");

	return 0;
}

