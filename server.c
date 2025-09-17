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

static pid_t	g_cur_client_pid = 0;

void	handler(int sig, siginfo_t *info, void *smth)
{
	static int	bits_count = 0;
	static char	byte = 0;
	(void)smth;

	if (g_cur_client_pid != info->si_pid)
	{
		g_cur_client_pid = info->si_pid;
		bits_count = 0;
		byte = 0;
		ft_printf("New client PID: %d\n", g_cur_client_pid);
	}
	ft_printf("Exited if condition pid check\n");
	if (sig == SIGUSR1)
		byte = (byte >> (7 - bits_count)) | 1;
	ft_printf("after if byte changing conditionn");
	bits_count++;
	if (bits_count == 7)
	{
		ft_printf("print the fucking BYTE CONDITION\n");
		ft_printf("%c", byte);
		bits_count = 0;
		byte = 0;
	}
	// kill(g_cur_client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t		server_pid;
	struct		sigaction sa;
	
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
	while (1)
		pause();
	return (0);
}