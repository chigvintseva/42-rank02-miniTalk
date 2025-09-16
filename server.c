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
	sigaddset(&sa.sa_mask, SIG_BIT_ONE);
	sigaddset(&sa.sa_mask, SIG_BIT_ZERO);
	sigaction(SIG_BIT_ONE, &sa, NULL);
	sigaction(SIG_BIT_ZERO, &sa, NULL);
	byte = 0;
	bits_count = 0;
	while (1)
	{
		pause();
	}
	return (0);
}