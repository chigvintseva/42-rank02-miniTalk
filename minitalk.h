/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:43 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/18 15:20:49 by achigvin         ###   ########.fr       */
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

void			args_error_msg(void);
void			send_byte(char current_byte);
void			ack_from_server(int signal);
void			add_new_client(pid_t client_pid);
client_info_t	*find_client(pid_t client_pid);
void			free_client(pid_t client_pid);
void			handler(int sig, siginfo_t *info, void *smth);

#endif