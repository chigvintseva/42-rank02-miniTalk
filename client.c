/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:33 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/18 16:50:40 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static pid_t	g_cur_server_pid;

int	main(int argc, char **argv)
{
	char				*message;
	long				current_byte;
	struct sigaction	sa;

	if (argc != 3)
		return (args_error_msg(), 1);
	g_cur_server_pid = ft_atoi(argv[1]);
	message = argv[2];
	current_byte = 0;
	sa.sa_handler = ack_from_server;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (message[current_byte] != '\0')
	{
		send_byte(message[current_byte]);
		current_byte++;
	}
	send_byte(message[current_byte]);
	pause();
	return (0);
}

void	ack_from_server(int signal)
{
	if (signal == SIGUSR2)
	{
		ft_printf_styled("Message is received by server\n", 'y', 'i');
	}
}

void	send_byte(char current_byte)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((current_byte >> bit) & 1) == 1)
			kill(g_cur_server_pid, SIGUSR1);
		else
			kill(g_cur_server_pid, SIGUSR2);
		pause();
		bit--;
	}
}
