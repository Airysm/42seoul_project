/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:12:44 by dseo              #+#    #+#             */
/*   Updated: 2022/01/10 13:40:49 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void);
void	compare_write(int i, int j, int k);

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = '0';
	j = '0';
	k = '0';
	compare_write(i, j, k);
}

void	compare_write(int i, int j, int k)
{
	char	num[3];

	while (i < '9' + 1)
	{
		num[0] = i;
		num[1] = j;
		num[2] = k;
		if (i < j && j < k)
		{
			write(1, num, 3);
			if (i != 55)
				write(1, ", ", 2);
		}
		k++;
		if (k == '9' + 1)
		{
			k = '0';
			j++;
		}
		if (j == '9' + 1)
		{
			j = '0';
			i++;
		}
	}
}
