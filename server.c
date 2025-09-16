/* ************************************************************************** */
/*                                                                            */
 /*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:46 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/14 16:32:00 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_client	*clients_management(pid_t cur_client_pid, t_client *clients, int *client_count)
{
	long	i;

	while (i < *client_count)
	{
		if (clients[i].pid == pid)
			return (&clients[i]);
		i++;
	}
}

void	handler(int sig, siginfo_t *info, int *bits_count, char *byte)
{
	if (cur_client_pid != info->si_pid)
	{
		cur_client_pid = info->si_pid;
		*bits_count = 0;
		*byte = 0;
	}
	if (sig == SIGUSR1)
	{
		*byte = (*byte >> (7 - *bits_count)) | 1;
		(*bits_count)++;
	}
	else if (sig == SIGUSR2)
		(*bits_count)++;
	// & check wether it is other signal like crush case or smth????? in the client i mean
	if (*bits_count == 7)
	{
		write(1, &(*byte), 1);
		*bits_count = 0;
		*byte = 0;
	}
}

int	main(void)
{
	pid_t	server_pid;
	struct	sigaction sa;
	char	byte;
	int		bits_count;
	
	server_pid = getpid();
	ft_printf("Server's PID: %d\n", (int)server_pid);

	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	byte = 0;
	bits_count = 0;
	while (1)
	{
		pause();
	}
	return (0);
}