/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:29:22 by dseo              #+#    #+#             */
/*   Updated: 2022/05/09 22:25:32 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	begin;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	begin = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[begin]) && s1[begin] != '\0')
		begin++;
	while (ft_strchr(set, s1[end - 1]) && end > begin)
		end--;
	str = (char *)malloc(sizeof(char) * (end - begin + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[begin], end - begin + 1);
	return (str);
}
