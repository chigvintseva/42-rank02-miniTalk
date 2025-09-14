/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:46 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/14 13:45:46 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"


int	main(void)
{
	pid_t	server_pid;
	char	byte;
	int		bits_count;
	
	server_pid = getpid();
	ft_printf("Server's PID: %d\n", (int)server_pid);
	while (1)
	{
		
	}
	return (0);
}