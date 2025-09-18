/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 15:40:56 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/18 16:51:24 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_clients_info	*g_clients = NULL;

int	main(void)
{
	pid_t				server_pid;
	struct sigaction	sa;

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

void	handler(int sig, siginfo_t *info, void *smth)
{
	t_clients_info	*client;

	(void)smth;
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
	if (client->bits_count == 8)
	{
		if (client->byte == 0)
			kill(client->client_pid, SIGUSR2);
		write(1, &(client->byte), 1);
		client->bits_count = 0;
		client->byte = 0;
		free_client(info->si_pid);
	}
	kill(client->client_pid, SIGUSR1);
}

void	add_new_client(pid_t client_pid)
{
	t_clients_info	*new_client;

	new_client = (t_clients_info *)malloc(sizeof(t_clients_info));
	if (!new_client)
	{
		ft_printf_styled("Memory allocation error\n", 'r', '0');
		exit(1);
	}
	new_client->client_pid = client_pid;
	new_client->bits_count = 0;
	new_client->byte = 0;
	new_client->next = g_clients;
	g_clients = new_client;
}

t_clients_info	*find_client(pid_t client_pid)
{
	t_clients_info	*cur_client_node;

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
	t_clients_info	*cur_client;
	t_clients_info	*previous_client;

	cur_client = g_clients;
	previous_client = NULL;
	while (cur_client != NULL)
	{
		if (cur_client->client_pid == client_pid)
		{
			if (previous_client == NULL)
				g_clients = cur_client->next;
			else
				previous_client->next = cur_client->next;
			free(cur_client);
			kill(client_pid, SIGUSR1);
			return ;
		}
		previous_client = cur_client;
		cur_client = cur_client->next;
	}
	ft_printf("No Client with PID %d found\n", (int)client_pid);
}
