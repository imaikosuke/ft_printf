/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 00:04:39 by koimai            #+#    #+#             */
/*   Updated: 2023/10/23 10:11:55 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_num_len(unsigned int n)
{
	size_t	len;

	len = 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_uitoa(unsigned int n)
{
	size_t	len;
	char	*result;

	len = ft_num_len(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (n != 0)
	{
		result[len - 1] = n % 10 + ('a' - 'A');
		n /= 10;
		len--;
	}
	return (result);
}

size_t	ft_put_uint(unsigned int n)
{
	size_t	len;
	char	*str;

	len = 0;
	if (n == 0)
		len += ft_put_char('0');
	else
	{
		str = ft_uitoa(n);
		len += ft_put_str(str);
		free(str);
	}
	return (len);
}
