/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:43 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/14 15:49:03 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>

typedef struct	s_client
{
	pid_t			pid;
	unsigned char	byte;
	int				bits_count;
} t_client;

void	args_error_msg(void);
void	send_byte(char current_byte, pid_t server_pid);
void	ack_from_server(int signal);
void	handler(int sig, siginfo_t *info, int *bits_count, char *byte);

#endif