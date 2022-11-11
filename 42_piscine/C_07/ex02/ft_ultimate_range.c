/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:16:48 by dseo              #+#    #+#             */
/*   Updated: 2022/01/24 13:33:03 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*list;
	int	i;

	if (min >= max)
	{
		list = 0;
		*range = list;
		return (0);
	}
	list = (int *)malloc(sizeof(int) * (max - min));
	if (list == 0)
		return (-1);
	i = 0;
	while (min < max)
	{
		list[i] = min;
		min++;
		i++;
	}
	*range = list;
	return (i);
}
