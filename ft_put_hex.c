/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:34:27 by koimai            #+#    #+#             */
/*   Updated: 2023/10/23 10:12:53 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_hex_len(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

size_t	ft_put_hex_util(unsigned int n, const char format)
{
	static size_t	len = 0;

	if (16 <= n)
	{
		ft_put_hex_util(n / 16, format);
		ft_put_hex_util(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_put_char(n - 10 + 'a');
		else
		{
			if (format == 'x')
				ft_put_char(n - 10 + 'a');
			if (format == 'X')
				ft_put_char(n - 10 + 'A');
		}
	}
	len++;
	return (len);
}

size_t	ft_put_hex(unsigned int n, const char format)
{
	size_t	len;
	
	len = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
		len += ft_put_hex_util(n, format);
	// else
		// ft_put_hex(n, format);
	// return (ft_hex_len(n));
	return (len);
}