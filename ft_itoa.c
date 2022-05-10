/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:31:12 by dseo              #+#    #+#             */
/*   Updated: 2022/04/29 20:28:14 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n);
static int		num_digit(int n);

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	long	num;

	digit = num_digit(n);
	num = (long)n;
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		num *= -1;
		str[0] = '-';
	}
	if (num == 0)
		str[0] = '0';
	str[digit] = '\0';
	while (num != 0)
	{
		str[digit - 1] = num % 10 + '0';
		num /= 10;
		digit--;
	}
	return (str);
}

static int	num_digit(int n)
{
	int	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}
