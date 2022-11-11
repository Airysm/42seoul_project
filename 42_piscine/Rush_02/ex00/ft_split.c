/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:59:36 by dseo              #+#    #+#             */
/*   Updated: 2022/01/23 16:59:37 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_split.h"

int	count_num(char *num)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (num[i] != ':')
	{
		if (num[i] == ' ')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	count++;
	return (count);
}

int	count_str(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != ':')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	count++;
	return (count);
}

void	split_str(char **num, char **str, char *read, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	num[i] = (char *)malloc(sizeof(char) * count_num(read));
	str[i] = (char *)malloc(sizeof(char) * count_str(read));
	while (read[j] != ':')
	{
		if (read[j] != ' ')
			(num[i])[k++] = read[j];
		j++;
	}
	(num[i])[k] = '\0';
	j++;
	k = 0;
	while (read[j] != '\0')
	{
		if (read[j] != ' ' && read[j] != '\n')
			(str[i])[k++] = read[j];
		j++;
	}
	(str[i])[k] = '\0';
}
