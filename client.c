#include "minitalk.h"

int signum_received;

static void signal_handler(int signum) 
{
    (void)signum;
    signum_received = 1;
}

void send_char_to_server(int server_pid, char c) 
{
    int i;

    i = 0;
    while (i < 8) {
        signum_received = 0;

        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        while (!signum_received)
            pause();
        i++;
    }
}

int main(int argc, char *argv[])
{
    int i;
    int server_pid;
    struct sigaction sa;
    char *message;

    i = 0;
    if (argc != 3) {
        write(1, "The enter type should be like: ./client <server_pid> <message>\n", 59);
        return (1);
    }
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0 || kill(server_pid, 0) == -1) 
    {
        write(1, "Invalid server PID.\n", 20);
        return (1);
    }
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    message = argv[2];
    while (message[i])
        send_char_to_server(server_pid, message[i++]);
    send_char_to_server(server_pid, '\0');
    return (0);
}