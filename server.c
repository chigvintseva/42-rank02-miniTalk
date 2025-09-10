/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:46 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/10 14:15:01 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minitalk.h"


int	main(void)
{
	pid_t	server_pid;
	
	server_pid = getpid();
	ft_printf("Server's PID: %d\n", (int)server_pid);
	

	return (0);
}