/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:29:01 by dseo              #+#    #+#             */
/*   Updated: 2022/05/09 22:02:47 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_split(char const *s, char c);
static size_t	c_count(char const *s, char c);
static size_t	point_set(char const *s, char c, size_t *i);
static char		*ft_strndup(char const *s, size_t size);
static char		**split_free(char **split);

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	len;
	size_t	point;
	size_t	i;

	len = 0;
	i = 0;
	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (c_count(s, c) + 1));
	if (!split)
		return (NULL);
	while (s[i] != '\0')
	{
		point = point_set(s, c, &i);
		if (point > 0)
		{
			split[len] = ft_strndup(&s[i], point);
			if (!split[len++])
				return (split_free(split));
			i += point;
		}
	}
	split[len] = NULL;
	return (split);
}

static size_t	c_count(char const *s, char c)
{
	size_t	count;
	size_t	len;
	size_t	i;

	count = 0;
	len = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
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
	return (len);
}

static size_t	point_set(char const *s, char c, size_t *i)
{
	size_t	point;

	point = 0;
	while (s[*i] == c)
		*i += 1;
	while (s[*i + point] != c && s[*i + point] != '\0')
		point++;
	return (point);
}

static char	*ft_strndup(char const *s, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	while (i < size && s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**split_free(char **split)
{
	size_t	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}
