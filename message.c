/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:42:17 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/11 15:15:31 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	args_error_msg(void)
{
	ft_printf_styled("Too few/many arguments are passed.\n", 'r', 'b');
	ft_printf_styled("There should be only 2 arguments:\n   1. Server's PID (where to send the message)\n   2. Message\n", 'w', 'i');
	ft_printf_styled("Example: ./client 4242 \"This message will be received by the server with PID 4242\"\n", 'y', 'i');
}