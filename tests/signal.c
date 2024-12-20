#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include "../libft/include/libft.h"
void sig_handler(int signum) {
	printf("Received SIGTERM. Exiting gracefully...\n%d\n", signum);
	// Perform cleanup or other necessary actions before exiting
	_exit(0);
}

int main() {
	// Set custom signal handler for SIGTERM
	pid_t pid = getpid();

	ft_printf("my pid: %d\n", pid);
	signal(SIGINT, sig_handler); 
	while (1) {
	printf("Press Ctrl+C to send SIGTERM...\n");
	sleep(1);
	}
	return 0;
}
