/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsevigen <bsevigen@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:01:50 by bsevigen          #+#    #+#             */
/*   Updated: 2026/01/17 18:24:50 by bsevigen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>

void	send_char_to_server(int server_pid, char c);
void	get_char_from_client(int signum, siginfo_t *info, void *context);
void	ft_putnbr(int n);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

#endif