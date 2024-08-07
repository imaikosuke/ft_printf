/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:50:03 by koimai            #+#    #+#             */
/*   Updated: 2024/07/08 17:39:01 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_ptr_len(uintptr_t n)
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

static size_t	ft_put_ptr_util(uintptr_t n)
{
	size_t	len;

	len = 0;
	if (16 <= n)
	{
		ft_put_ptr_util(n / 16);
		ft_put_ptr_util(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_put_char(n + '0');
		else
			ft_put_char(n - 10 + 'a');
	}
	len++;
	return (len);
}

size_t	ft_put_ptr(unsigned long long ptr)
{
	size_t	len;

	len = 0;
	len += write(1, "0x", 2);
	if (ptr == 0)
		len += write(1, "0", 1);
	else
	{
		ft_put_ptr_util(ptr);
		len += ft_ptr_len(ptr);
	}
	return (len);
}
