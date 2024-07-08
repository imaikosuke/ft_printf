/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:57:06 by koimai            #+#    #+#             */
/*   Updated: 2024/05/09 14:56:42 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
size_t	ft_put_char(int c);
size_t	ft_put_str(char *str);
size_t	ft_put_nbr(int n);
size_t	ft_put_percent(void);
size_t	ft_put_hex(unsigned int n, const char format);
size_t	ft_put_ptr(unsigned long long ptr);
size_t	ft_put_uint(unsigned int n);

#endif