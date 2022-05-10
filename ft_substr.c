/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:30:50 by dseo              #+#    #+#             */
/*   Updated: 2022/05/09 22:32:36 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	len_sub;
	size_t	i;

	if (!s)
		return (NULL);
	len_sub = ft_strlen(s) - start;
	if (len_sub < len && len_sub >= 0)
		len = len_sub;
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && i + start < ft_strlen(s))
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
