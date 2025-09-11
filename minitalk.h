/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:43 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/11 15:07:23 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define SIG_BIT_ONE SIGUSR1
# define SIG_BIT_ZERO SIGUSR2

# include "libft/libft.h"
# include <unistd.h>
# include <signal.h>

void	args_error_msg(void);

#endif