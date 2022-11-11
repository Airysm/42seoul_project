/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:29:55 by dseo              #+#    #+#             */
/*   Updated: 2022/01/10 13:57:51 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	write_num(char *num1, char *num2);
void	value_num(char *num1, char *num2);
void	plus_num(char *num);

void	ft_print_comb2(void)
{
	char	num1[3];
	char	num2[2];

	num1[0] = '0';
	num1[1] = '0';
	num1[2] = ' ';
	while (num1[0] <= '9')
	{
		value_num(num1, num2);
		while (num2[0] <= '9')
		{
			write_num(num1, num2);
			num2[1]++;
			plus_num(num2);
		}
		num1[1]++;
		plus_num(num1);
	}
}

void	write_num(char *num1, char *num2)
{
	write(1, num1, 3);
	write(1, num2, 2);
	if ((num1[0] != '9') || (num1[1] != '8'))
		write(1, ", ", 2);
}

void	value_num(char *num1, char *num2)
{
	if (num1[1] == '9')
	{
		num2[0] = num1[0] + 1;
		num2[1] = '0';
	}
	else
	{
		num2[0] = num1[0];
		num2[1] = num1[1] + 1;
	}
}

void	plus_num(char *num)
{
	if (num[1] == '9' + 1)
	{
		num[0] = num[0] + 1;
		num[1] = '0';
	}
}
