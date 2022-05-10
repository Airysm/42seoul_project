/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:30:38 by dseo              #+#    #+#             */
/*   Updated: 2022/05/10 19:14:25 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
