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

client_info_t	*g_clients = NULL;

void	add_new_client(pid_t client_pid)
{
	client_info_t	*new_client;

	new_client = (client_info_t *)malloc(sizeof(client_info_t));
	if (!new_client)
	{
		ft_printf("memory allocation error");
		exit(1);
	}
	new_client->client_pid = client_pid;
	new_client->bits_count = 0;
	new_client->byte = 0;
	new_client->next = g_clients;
 g_clients = new_client;
}

client_info_t	*find_client(pid_t client_pid)
{
	client_info_t	*cur_client_node;

	cur_client_node = g_clients;
	while (cur_client_node != NULL)
	{
		if (cur_client_node->client_pid == client_pid)
			return (cur_client_node);
		cur_client_node = cur_client_node->next;
	}
	return (NULL);
}

void	free_client(pid_t client_pid)
{
	// client_info_t	*current_node;
	// client_info_t	*previous_node;

	// previous_node = NULL;
	// current_node = g_clients;
	// while (current_node != NULL)
	// {
	// 	if (current_node->client_pid == client_pid)
	// }
	ft_printf("\n cleint with pid %d will be freed\n", client_pid);
}

void	handler(int sig, siginfo_t *info, void *smth)
{
	(void)smth;
	client_info_t	*client;

	client = find_client(info->si_pid);
	if (!client)
	{
		add_new_client(info->si_pid);
		client = find_client(info->si_pid);
	}
	if (sig == SIGUSR1)
		client->byte = ((client->byte) << 1) | 1;
	else if (sig == SIGUSR2)
		client->byte = ((client->byte) << 1);
	client->bits_count++;
//	ft_printf("Bits received: %d, Current byte: %d\n", bits_count, byte);
//	ft_printf("now bits_count is %d\n", bits_count);`
	if (client->bits_count == 8)
	{
//		ft_printf("print the fucking BYTE CONDITION\n");
		write(1, &(client->byte), 1);
		client->bits_count = 0;
		client->byte = 0;
		free_client(info->si_pid);
	}
	kill(client->client_pid, SIGUSR1);
}

int	main(void)
{
	pid_t					server_pid;
	struct					sigaction sa;
	
	server_pid = getpid();
	ft_printf("Server's PID: %d\n", (int)server_pid);
	memset(&sa, 0, sizeof(sa));
	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}