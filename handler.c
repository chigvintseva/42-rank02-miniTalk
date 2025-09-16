/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 15:18:34 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/14 15:18:44 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *info, int *bits_count, char *byte)
{
	if (cur_client_pid != info->si_pid)
	{
		cur_client_pid = info->si_pid;
		*bits_count = 0;
		*byte = 0;
	}
	if (sig == SIG_BIT_ONE)
	{
		*byte = (*byte >> (7 - *bits_count)) | 1;
		(*bits_count)++;
	}
	else if (sig == SIG_BIT_ZERO)
		(*bits_count)++;
	// & check wether it is other signal like crush case or smth????? in the client i mean
	if (*bits_count == 7)
	{
		write(1, &(*byte), 1);
		*bits_count = 0;
		*byte = 0;
	}
}