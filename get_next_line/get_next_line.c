/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:41:34 by dseo              #+#    #+#             */
/*   Updated: 2022/08/24 06:42:53 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_strchr(const char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	c %= 256;
	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)&s[i]);
}

char	*read_all(char *str, int fd)
{
	char	*temp;
	ssize_t	read_size;

	temp = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	read_size = 1;
	while (gnl_strchr(str, '\n') == NULL && read_size > 0)
	{
		read_size = read(fd, temp, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[read_size] = '\0';
		str = ft_strjoin(str, temp);
		if (!str)
		{
			free(temp);
			return (NULL);
		}
	}
	free(temp);
	return (str);
}

char	*save_str(char *str, int *error_num)
{
	char	*temp;
	size_t	i;
	size_t	j;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (NULL);
	temp = (char *)malloc(ft_strlen(str) - i + 1);
	if (!temp)
	{
		*error_num = -1;
		return (NULL);
	}
	i++;
	j = 0;
	while (str[i + j] != '\0')
	{
		temp[j] = str[i + j];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*read_str(char *str)
{
	char	*temp;
	size_t	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	else if (str[i] == '\n')
		i++;
	temp = (char *)malloc(i + 1);
	if (!temp)
	{
		free(str);
		return (NULL);
	}
	ft_strlcpy(temp, str, i + 1);
	free(str);
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*save;
	int			error_num;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!save)
		str = NULL;
	else
	{
		str = ft_strdup(save);
		free(save);
		if (!str)
			return (NULL);
	}
	str = read_all(str, fd);
	if (!str)
		return (NULL);
	error_num = 0;
	save = save_str(str, &error_num);
	if (!save && (error_num == -1))
		return (NULL);
	str = read_str(str);
	return (str);
}
