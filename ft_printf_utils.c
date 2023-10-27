/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: koimai <koimai@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 18:06:11 by koimai            #+#    #+#             */
/*   Updated: 2023/10/27 17:31:53 by koimai           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_put_char(int c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_put_str(char *str)
{
	size_t	i;

	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_put_char(str[i]);
		i++;
	}
	return (i);
}

size_t	ft_put_nbr(int n)
{
	size_t	len;
	char	*str;

	str = ft_itoa(n);
	len = ft_put_str(str);
	free(str);
	return (len);
}

size_t	ft_put_percent(void)
{
	write(1, "%", 1);
	return (1);
}
