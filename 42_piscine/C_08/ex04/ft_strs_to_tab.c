/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 09:30:43 by dseo              #+#    #+#             */
/*   Updated: 2022/01/24 09:32:59 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);
char				*ft_strdup(char *src);
int					str_size(char *str);

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strs;
	int			i;

	strs = (t_stock_str *)malloc(sizeof(t_stock_str) * ac);
	if (strs == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		strs[i].size = str_size(av[i]);
		strs[i].str = (char *)malloc(sizeof(char) * (str_size(av[i]) + 1));
		strs[i].copy = (char *)malloc(sizeof(char) * (str_size(av[i]) + 1));
		strs[i].str = av[i];
		strs[i].copy = ft_strdup(av[i]);
		i++;
	}
	strs[i].str = 0;
	return (strs);
}

char	*ft_strdup(char *src)
{
	char	*str;
	int		ssize;
	int		i;

	i = 0;
	ssize = 0;
	while (src[ssize] != '\0')
		ssize++;
	str = (char *)malloc(sizeof(char) * (ssize + 1));
	if (str == 0)
		return (0);
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	str_size(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
