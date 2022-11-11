/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:01:07 by dseo              #+#    #+#             */
/*   Updated: 2022/01/26 19:58:08 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base);
void	putnbr_change(unsigned int num, char *base, unsigned int bsize);
int		base_chk(char *base, unsigned int bsize);

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	num;
	unsigned int	bsize;

	bsize = 0;
	while (base[bsize] != '\0')
		bsize++;
	if (base_chk(base, bsize))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		num = (unsigned int)nbr * -1;
	}
	else
		num = (unsigned int)nbr;
	putnbr_change(num, base, bsize);
}

void	putnbr_change(unsigned int num, char *base, unsigned int bsize)
{
	if (num >= bsize)
	{
		putnbr_change(num / bsize, base, bsize);
		write(1, &base[num % bsize], 1);
	}
	else
		write(1, &base[num % bsize], 1);
}

int	base_chk(char *base, unsigned int bsize)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (bsize <= 1)
		return (1);
	while (i < bsize)
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (j < bsize)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
