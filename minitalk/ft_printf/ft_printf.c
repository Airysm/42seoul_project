/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 17:30:45 by dseo              #+#    #+#             */
/*   Updated: 2022/07/23 18:11:01 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *args, ...);
int	chk_error(int temp, int *len);

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		temp;
	int		len;
	int		i;

	va_start(ap, args);
	len = 0;
	i = 0;
	while (args[i] != '\0')
	{
		if (args[i] == '%')
		{
			i++;
			temp = ft_print_add(ap, args[i]);
			if (chk_error(temp, &len))
				break ;
			len += temp;
		}
		else
			len += ft_putchar(args[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

int	chk_error(int temp, int *len)
{
	if (temp == -1)
	{
		*len = -1;
		return (1);
	}
	return (0);
}
