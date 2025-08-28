/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achigvin <achigvin@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 18:55:51 by achigvin          #+#    #+#             */
/*   Updated: 2025/05/30 18:55:53 by achigvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *s, ...);
int		ft_charinput(char arg);
int		ft_strinput(char *str);
int		ft_intinput(int arg);
int		ft_nbrbase(unsigned long num, char *base, int fd);
int		ft_ptrinput(long arg);
char	*ft_ltoa(unsigned long n);
int		ft_uinput(unsigned long arg);

#endif
