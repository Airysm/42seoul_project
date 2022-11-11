/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:00:35 by dseo              #+#    #+#             */
/*   Updated: 2022/01/23 21:54:13 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_lib.h"

unsigned int key[100] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
	11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 100, 1000, 1000000 };

char value[100][100] = { "zero", "one", "two", "three", "four", "five",
	"six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen",
	"fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
	"twenty", "thirty", "forty", "hundred", "thousand", "million" };

void print_level(int size)
{
	int level;
	int i;
	int unit;

	if(size < 3)
		return ;
	level = size / 3;
	i = 0;
	unit = 1;
	while (i < level)
	{
		unit = unit * 1000;
		i++;
	}
	printf("%s", value[unit]);
}
int	num_level(char *str)
{
	int	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}
int div_str(char *str, int size)
{
	int num;
	int	idx;
	int i;

	idx = size % 3;
	if (idx == 0 )
		idx = 3;
	i = 0;
	num = 0;
	while (str[i] == ' ')
		i++;
	while (i < idx + i)
	{
		num = num * 10 + str[i] - '0';
		str[i] = ' ';
		i++;
	}
	return (num);
}
void	print_3(int	num)
{
    int hundred;
    int ten;
    int one;
	int i;
	i = 0;
    hundred = num / 100;
    if (hundred > 0)
    {
        printf("%s", value[hundred]);
        printf(" hundred ");
	}
    ten = num % 100;
	if (ten != 0 && (ten >= 10 && ten < 20))
		printf("%s", value[ten]);
	else
	{
		one = ten % 10;
		ten = ten - one;
		if (ten != 0)
			printf("%s ", value[ten]);
		if (one != 0)
			printf("%s ", value[one]);
	}
}

void	print_input(char **key, char **value, char *input, int dict_size)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		printf("key: %s, value: %s\n", key[i], value[i]);
		i++;
	}
	printf("%s\n", input);
}
