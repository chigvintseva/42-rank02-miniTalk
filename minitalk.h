/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:43 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/18 17:01:51 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <string.h>

typedef struct s_clients_info
{
	pid_t					client_pid;
	int						bits_count;
	unsigned char			byte;
	struct s_clients_info	*next;
}	t_clients_info;

void			args_error_msg(void);
void			no_pid_msg(void);
int				check_server_exists(pid_t server_pid);
void			send_byte(char current_byte);
void			ack_from_server(int signal);
void			add_new_client(pid_t client_pid);
t_clients_info	*find_client(pid_t client_pid);
void			free_client(pid_t client_pid);
void			handler(int sig, siginfo_t *info, void *smth);

#endif