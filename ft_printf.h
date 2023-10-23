/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:57:06 by koimai            #+#    #+#             */
/*   Updated: 2023/10/23 10:05:41 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

size_t	ft_format(va_list args, const char format);
char	*ft_itoa(int n);
size_t	ft_put_char(char c);
size_t	ft_put_str(char *str);
size_t	ft_put_nbr(int n);
size_t	ft_put_percent(void);
size_t	ft_format(va_list args, const char format);
int		ft_printf(const char *str, ...);
size_t	ft_put_hex(unsigned int n, const char format);
size_t	ft_put_ptr(unsigned long long ptr);
size_t	ft_put_uint(unsigned int n);

#endif