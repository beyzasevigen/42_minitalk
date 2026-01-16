#include "minitalk.h"

static void print_pid(void)
{
    ft_putnbr(getpid());
    write(1, "\n", 1);
}
// static int	get_signal(int signal, siginfo_t *info, void *context)
// {
// 	if (signal == SIGUSR1)
// 		return (0);
// 	else if (signal == SIGUSR2)
// 		return (1);
// 	return (-1);
// }

void get_char_from_client(int signum, siginfo_t *info, void *context)
{
    static char c;
    static int i;

    (void) context;
    if (signum == SIGUSR1)
        c |= (1 << i);
    i++;
    if (i == 8) {
        write(1, &c, 1);
        i = 0;
        c = 0;
    }
    kill(info->si_pid, SIGUSR1);
}   

int main(void)
{
    struct sigaction sa;

    print_pid();
    sa.sa_sigaction = get_char_from_client;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
    while (1)
        pause();
    return (0);
}
