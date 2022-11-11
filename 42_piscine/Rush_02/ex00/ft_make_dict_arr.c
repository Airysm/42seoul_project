/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_dict_arr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:59:26 by dseo              #+#    #+#             */
/*   Updated: 2022/01/23 16:59:28 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "ft_lib.h"
#include "ft_split.h"
#include "ft_print_input.h"

char	*read_file(char *file_name)
{
	int		fd;
	int		n;
	char	*result_buf;
	char	*result_pos;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	result_buf = (char *)malloc(sizeof(char) * 1024);
	result_pos = result_buf;
	while (1)
	{
		n = read(fd, result_buf, 1);
		if (n == -1 || *result_buf == EOF || *result_buf == '\0')
			break ;
		result_buf++;
	}
	free (result_pos);
	return (result_pos);
}

void	free_dict(char **num, char **str, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(num[j]);
		free(str[j]);
		j++;
	}
}

void	make_dict_arr(char *file_name, char *n)
{
	char	*pos;
	char	*find;
	char	*num[100];
	char	*str[100];
	int		i;

	pos = read_file(file_name);
	find = ft_strchr(pos, '\n');
	i = 0;
	while (find != 0 && *find != '\0')
	{
		*find = '\0';
		split_str(num, str, pos, i);
		pos = ++find;
		i++;
		find = ft_strchr(pos, '\n');
	}
	print_input(num, str, n, i);
	free_dict(num, str, i);
}
