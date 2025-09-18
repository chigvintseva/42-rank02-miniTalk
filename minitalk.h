/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:43 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/17 18:08:17 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <string.h>

typedef struct client_info
{
	pid_t				client_pid;
	int					bits_count;
	unsigned char		byte;
	struct client_info	*next;
} client_info_t;

void	args_error_msg(void);
void	send_byte(char current_byte);
void	ack_from_server(int signal);
void	handler(int sig, siginfo_t *info, void *smth);

#endif