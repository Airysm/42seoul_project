/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:01:07 by dseo              #+#    #+#             */
/*   Updated: 2022/07/22 19:53:34 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_hex(unsigned long nbr, int flag);
int		ft_putnbr_base(unsigned long nbr, char *base);
void	putnbr_change(unsigned long nbr, char *base,
			unsigned long bsize, int *len);

int	ft_putnbr_hex(unsigned long nbr, int flag)
{
	unsigned int	num;
	int				len;

	num = (unsigned int)nbr;
	if (flag == 2)
	{
		len = ft_putstr("0x");
		len += ft_putnbr_base(nbr, "0123456789abcdef");
	}
	else if (flag == 1)
		len = ft_putnbr_base(num, "0123456789ABCDEF");
	else
		len = ft_putnbr_base(num, "0123456789abcdef");
	return (len);
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long	bsize;
	int				len;

	bsize = 0;
	while (base[bsize] != '\0')
		bsize++;
	len = 0;
	putnbr_change(nbr, base, bsize, &len);
	return (len);
}

void	putnbr_change(unsigned long nbr, char *base,
			unsigned long bsize, int *len)
{
	if (nbr >= bsize)
	{
		putnbr_change(nbr / bsize, base, bsize, len);
		write(1, &base[nbr % bsize], 1);
		*len += 1;
	}
	else
	{
		write(1, &base[nbr % bsize], 1);
		*len += 1;
	}
}
