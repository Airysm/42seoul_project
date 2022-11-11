/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:17:07 by dseo              #+#    #+#             */
/*   Updated: 2022/01/25 15:15:59 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(int size, char **strs, char *sep);
char	*ft_strcat(char *dest, char *src);
int		strslen(char **strs, int size, int sep_size);

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		sep_size;
	int		i;
	int		len;

	sep_size = 0;
	while (sep[sep_size] != '\0')
		sep_size++;
	len = strslen(strs, size, sep_size);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	if (size == 0)
		return (result);
	result[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(result, strs[i]);
		if (i != size - 1)
			ft_strcat(result, sep);
		i++;
	}
	return (result);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dsize;

	i = 0;
	dsize = 0;
	while (dest[dsize] != '\0')
		dsize++;
	while (src[i] != '\0')
	{
		dest[dsize + i] = src[i];
		i++;
	}
	dest[dsize + i] = '\0';
	return (dest);
}

int	strslen(char **strs, int size, int sep_size)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < size)
	{
		j = 0;
		while ((strs[i])[j] != '\0')
		{
			count++;
			j++;
		}
		if (i != size - 1)
			count += sep_size;
		i++;
	}
	return (count);
}
