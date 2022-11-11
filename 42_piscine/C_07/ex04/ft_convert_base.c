/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:19:18 by dseo              #+#    #+#             */
/*   Updated: 2022/01/26 17:38:46 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
void	ft_putnbr_base(int nbr, char *base, char *result);
void	putnbr_change(unsigned int num, char *base,
			char *result, int *index);
int		putnbr_size(char *base_to, int nbr_int);
int		ft_atoi_base(char *str, char *base);
int		base_chk_final(char *base_from, char *base_to);
void	size_count(unsigned int num, char *base_to, int *count);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		nbr_int;
	int		str_size;

	if (base_chk_final(base_from, base_to))
		return (0);
	nbr_int = ft_atoi_base(nbr, base_from);
	str_size = putnbr_size(base_to, nbr_int);
	result = (char *)malloc(sizeof(char) * (str_size + 1));
	ft_putnbr_base(nbr_int, base_to, result);
	return (result);
}

void	ft_putnbr_base(int nbr, char *base, char *result)
{
	unsigned int	num;
	unsigned int	bsize;
	int				index;

	bsize = 0;
	index = 0;
	while (base[bsize] != '\0')
		bsize++;
	if (nbr < 0)
	{
		result[index++] = '-';
		num = (unsigned int)nbr * -1;
	}
	else
		num = (unsigned int)nbr;
	putnbr_change(num, base, result, &index);
	result[index] = '\0';
}

void	putnbr_change(unsigned int num, char *base,
			char *result, int *index)
{
	unsigned int	bsize;

	bsize = 0;
	while (base[bsize] != '\0')
		bsize++;
	if (num >= bsize)
	{
		putnbr_change(num / bsize, base, result, index);
		result[*index] = base[num % bsize];
		*index += 1;
	}
	else
	{
		result[*index] = base[num % bsize];
		*index += 1;
	}
}

int	putnbr_size(char *base_to, int nbr_int)
{
	unsigned int	num;
	int				count;

	count = 0;
	if (nbr_int < 0)
	{
		num = (unsigned int)nbr_int * -1;
		count++;
	}
	else
		num = (unsigned int)nbr_int;
	size_count(num, base_to, &count);
	return (count);
}

void	size_count(unsigned int num, char *base_to, int *count)
{
	unsigned int	bsize;

	bsize = 0;
	while (base_to[bsize] != '\0')
		bsize++;
	if (num >= bsize)
		size_count(num / bsize, base_to, count);
	*count += 1;
}
