/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_styled.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:12:32 by achigvin          #+#    #+#             */
/*   Updated: 2025/09/10 19:27:26 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include "ft_printf.h"

void	reset(void)
{
	ft_printf("\e[0m");
}

void	ft_printf_styled(char *str, char colour, char style)
{
	if (colour == 'r')
		red(style);
	else if (colour == 'g')
		green(style);
	else if (colour == 'y')
		yellow(style);
	ft_printf(str);
	reset();
}