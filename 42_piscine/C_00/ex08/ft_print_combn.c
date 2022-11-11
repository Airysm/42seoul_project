/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 15:19:44 by dseo              #+#    #+#             */
/*   Updated: 2022/01/09 19:41:34 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	write_num(char *num, int n);
void	plus_num(char *num, int n);
int		compare_num(char *num, int n);

void	ft_print_combn(int n)
{
	char	num[10];

	num[0] = '0';
	num[1] = '1';
	num[2] = '2';
	num[3] = '3';
	num[4] = '4';
	num[5] = '5';
	num[6] = '6';
	num[7] = '7';
	num[8] = '8';
	num[9] = '9';
	while (num[0] <= (10 - n + '0'))
	{
		write_num(num, n);
		num[n - 1]++;
		plus_num(num, n);
	}
}

void	write_num(char *num, int n)
{
	int	i;

	if (compare_num(num, n))
	{
		i = 0;
		while (i < n)
		{
			write(1, &num[i], 1);
			i++;
		}
		if (num[0] != (10 - n + '0'))
			write(1, ", ", 2);
	}
}	

void	plus_num(char *num, int n)
{
	int	i;

	i = 1;
	while (n - (i + 1) >= 0)
	{
		if (num[n - i] == '9' + 1)
		{
			num[n - i] = '0';
			num[n - (i + 1)]++;
		}
		i++;
	}
}

int	compare_num(char *num, int n)
{
	int	i;

	i = 0;
	while (i < n - 1)
	{
		if (num[i] >= num[i + 1])
			return (0);
		i++;
	}
	return (1);
}
