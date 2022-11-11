/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 02:41:13 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 03:30:56 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen_without_nl(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0' && s[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlcpy_without_nl(char *dst, const char *src, \
	size_t dstsize)
{
	size_t	src_size;
	size_t	i;

	src_size = ft_strlen(src);
	i = 0;
	while (i < src_size && dstsize > i + 1 && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (src_size);
}

size_t	ft_strlcat_without_nl(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_size;
	size_t	src_size;
	size_t	i;

	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	i = 0;
	if (dstsize < dst_size)
		return (src_size + dstsize);
	while (i < src_size && (dstsize > dst_size + i + 1) && src[i] != '\n')
	{
		dst[dst_size + i] = src[i];
		i++;
	}
	if (i < dstsize)
		dst[dst_size + i] = '\0';
	return (dst_size + src_size);
}

char	*ft_strdup_without_nl(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_without_nl(char *s1, char *s2)
{
	char	*str;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup_without_nl(s2));
	else if (!s2)
		return (ft_strdup_without_nl(s1));
	s1_size = ft_strlen_without_nl(s1);
	s2_size = ft_strlen_without_nl(s2);
	str = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!str)
		return (NULL);
	ft_strlcpy_without_nl(str, s1, s1_size + 1);
	ft_strlcat_without_nl(str, (char *)s2, s1_size + s2_size + 1);
	free(s1);
	return (str);
}
