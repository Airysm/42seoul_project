/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 19:45:50 by dseo              #+#    #+#             */
/*   Updated: 2022/07/22 19:54:03 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_unsigned_len(unsigned int nb);
void	ft_putnbr_unsigned(unsigned int nb);

int	ft_putnbr_unsigned_len(unsigned int nb)
{
	int	len;

	ft_putnbr_unsigned(nb);
	len = 0;
	if (nb <= 0)
		len++;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	ft_putnbr_unsigned(unsigned int nb)
{
	char	c;

	if (nb >= 10)
	{
		c = (nb % 10) + '0';
		ft_putnbr_unsigned(nb / 10);
		write(1, &c, 1);
	}
	else
	{
		c = nb + '0';
		write(1, &c, 1);
	}
}
