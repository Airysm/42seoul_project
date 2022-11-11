/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:56:43 by dseo              #+#    #+#             */
/*   Updated: 2022/07/22 20:03:12 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_add(va_list ap, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar((char)(va_arg(ap, int)));
	else if (c == 's')
	{
		len = ft_putstr((char *)(va_arg(ap, char *)));
		if (len == -1)
			return (-1);
	}
	else if (c == 'p')
		len = ft_putnbr_hex((unsigned long)(va_arg(ap, void *)), 2);
	else if (c == 'd' || c == 'i')
		len = ft_putnbr_len((int)(va_arg(ap, int)));
	else if (c == 'u')
		len = ft_putnbr_unsigned_len((unsigned int)(va_arg(ap, unsigned int)));
	else if (c == 'x')
		len = ft_putnbr_hex((unsigned int)(va_arg(ap, unsigned int)), 0);
	else if (c == 'X')
		len = ft_putnbr_hex((unsigned int)(va_arg(ap, unsigned int)), 1);
	else if (c == '%')
		len = ft_putchar('%');
	return (len);
}
