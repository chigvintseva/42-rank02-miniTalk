/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:33 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/11 19:15:57 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ack_from_server(int signal)
{
	(void)signal;
}

void	send_byte(char current_byte, pid_t server_pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((current_byte >> bit) & 1) == 1)
		{
			kill(server_pid, SIGUSR1); 
			pause();
		}
		else
		{
			kill(server_pid, SIGUSR2);
			pause();
		}
		bit--;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*message;
	long	current_byte;
	struct	sigaction sa;

	if (argc != 3)
		return (args_error_msg(), 1);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	current_byte = 0;
	sa.sa_handler = ack_from_server;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (message[current_byte] != '\0')
	{
		send_byte(message[current_byte], server_pid);
		current_byte++;
	}
	send_byte(message[current_byte], server_pid);
	pause();
	return (0);
}