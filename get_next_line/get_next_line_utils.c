/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:41:52 by dseo              #+#    #+#             */
/*   Updated: 2022/08/24 05:56:11 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src,
	size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	while (i < src_size && dstsize > i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (dstsize < dst_size)
		return (src_size + dstsize);
	while (i < src_size && (dstsize > dst_size + i + 1))
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, s1_size + 1);
	ft_strlcat(str, (char *)s2, s1_size + s2_size + 1);
	free(s1);
	return (str);
}
