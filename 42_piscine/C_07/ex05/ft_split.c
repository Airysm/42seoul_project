/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 20:18:25 by dseo              #+#    #+#             */
/*   Updated: 2022/01/25 10:39:12 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_split(char *str, char *charset);
int		charset_count(char *str, char *charset);
int		charset_chk(char *charset, char c);

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		len;
	int		i;
	int		j;

	len = 0;
	i = -1;
	split = (char **)malloc(sizeof(char *) * charset_count(str, charset));
	while (str[++i] != '\0')
	{
		j = 0;
		while (!(charset_chk(charset, str[i + j])) && str[i + j] != '\0')
			j++;
		if (j > 0)
		{
			split[len] = (char *)malloc(sizeof(char) * (j + 1));
			j = 0;
			while (!(charset_chk(charset, str[i])) && str[i] != '\0')
				split[len][j++] = str[i++];
			split[len][j] = '\0';
			len++;
		}
	}
	split[len] = 0;
	return (split);
}

int	charset_count(char *str, char *charset)
{
	int	count;
	int	len;
	int	i;

	count = 0;
	len = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (charset_chk(charset, str[i]))
		{
			if (count != 0)
				len++;
			count = 0;
		}
		else
			count++;
		i++;
	}
	if (count != 0)
		len++;
	return (len + 1);
}

int	charset_chk(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}
