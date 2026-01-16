#include "minitalk.h"

void send_char_to_server(int server_pid, char c) {
    int i;

    i = 0;
    while (i < 8) {
        if ((c >> i) & 1)
            kill(server_pid, SIGUSR1);
        else
            kill(server_pid, SIGUSR2);
        pause();
    }
}

int main(int argc, char *argv[])
{
    int i;
    int server_pid;
    struct sigaction sa;

    i = 0;
    if (argc != 3) {
        write(1, "The enter type should be like: ./client <server_pid> <message>\n", 59);
        return (0);
    }
    server_pid = ft_atoi(argv[1]);
    if (server_pid <= 0) {
        write(1, "Invalid server PID.\n", 20);
        return (0);
    }
    char *message = argv[2];
    while (message[i])
        send_char_to_server(server_pid, message[i++]);
    send_char_to_server(server_pid, '\0');
    return 0;
}