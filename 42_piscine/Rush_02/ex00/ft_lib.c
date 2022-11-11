/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:59:56 by dseo              #+#    #+#             */
/*   Updated: 2022/01/23 17:02:24 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_lib.h"

unsigned int	ft_atoi(char *str)
{
	int				idx;
	int				minus;
	unsigned int	num;

	idx = 0;
	minus = 1;
	num = 0;
	while ((str[idx] >= 9 && str[idx] <= 13) || str[idx] == ' ' \
			|| str[idx] == '-' || str[idx] == '+')
		idx++;
	while (str[idx] != '\0' && (str[idx] >= '0' && str[idx] <= '9'))
	{
		num = num * 10 + (str[idx] - '0');
		idx++;
	}
	return (num);
}

void	free_memory(char **str)
{
	free(*str);
}

char	*ft_strchr(char *s, char c)
{
	while (*s != c)
	{
		if (*s == '\0')
			return (0);
		s++;
	}
	return ((char *)s);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	return (dest);
}
