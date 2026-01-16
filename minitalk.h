#ifndef MINITALK_H
#define MINITALK_H

#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void    send_char_to_server(int server_pid, char c);
void	ft_putnbr(int n);
int	    ft_atoi(const char *nptr);

#endif // MINITALK_H