/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:33 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/11 19:12:37 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_byte(char current_byte, pid_t server_pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		if (((current_byte >> bit) & 1) == 1)
		{
			kill(server_pid, SIG_BIT_ONE);
			pause();		
		}

		else
		{
			kill(server_pid, SIG_BIT_ZERO);
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

	if (argc != 3)
		return (args_error_msg(), 0);
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	current_byte = 0;
	while (message[current_byte] != '\0')
	{
		send_byte(message[current_byte], server_pid);
		current_byte++;
	}
	send_byte(message[current_byte], server_pid);
	return (0);
}