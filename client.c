/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:33 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/10 19:32:13 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char **argv)
{
	// if (argc != 3)
	// 	return (ft_printf_styled("Too few/many arguments are passed.\nThere should be only 2 arguments:\n   1. Server's PID (where to send the message)\n   2. Message\n\n Example: ./client 4242 \"This message will be received by the server with PID 4242\"", 'r', 'i'));
	ft_printf_styled("Too few/many arguments are passed.\nThere should be only 2 arguments:\n   1. Server's PID (where to send the message)\n   2. Message\n\n Example: ./client 4242 \"This message will be received by the server with PID 4242\"", 'r', 'i');
	return (0);
}