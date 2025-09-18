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
		perror("malloc");
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


void	del_client_free(pid_t client_pid)
{
	
}