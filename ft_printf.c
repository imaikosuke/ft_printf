/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 17:50:03 by koimai            #+#    #+#             */
/*   Updated: 2023/10/27 17:33:26 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_format(va_list args, const char format)
{
	size_t	len;

	len = 0;
	if (format == 'c')
		len += ft_put_char(va_arg(args, int));
	else if (format == 's')
		len += ft_put_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		len += ft_put_nbr(va_arg(args, int));
	else if (format == 'u')
		len += ft_put_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_put_hex(va_arg(args, unsigned int), format);
	else if (format == 'p')
		len += ft_put_ptr(va_arg(args, unsigned long long));
	else if (format == '%')
		len += ft_put_percent();
	return (len);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	size_t	len;
	va_list	args;

	len = 0;
	va_start(args, str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			len += ft_put_char(str[i]);
		else
		{
			i++;
			len += ft_format(args, str[i]);
		}
		i++;
	}
	va_end(args);
	return ((int)len);
}

#include <stdio.h>
int	main(void)
{
	int	len;

	printf("\n");
	len = ft_printf("[%c] [%c] [%c]", '0', 0, '0');
	printf("size:[ %d ]\n", len);
	len = printf("[%c] [%c] [%c]", '0', 0, '0');
	printf("size:[ %d ]\n", len);
	return (0);
}
