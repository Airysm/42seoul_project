/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:50:07 by dseo              #+#    #+#             */
/*   Updated: 2022/01/26 14:37:19 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	while (i + 1 < length)
	{
		if (flag == 0)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				flag = 1;
			else if (f(tab[i], tab[i + 1]) < 0)
				flag = 2;
		}
		else if (flag == 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
		}
		else if (flag == 2)
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
		i++;
	}
	return (1);
}
