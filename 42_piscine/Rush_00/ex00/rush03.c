/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 11:37:37 by dseo              #+#    #+#             */
/*   Updated: 2022/01/08 16:45:44 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern	void	ft_putchar(char c);
void		rush_x(int x, int y, int i);
void		rush(int x, int y);

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (i < y)
	{
		rush_x(x, y, i);
		ft_putchar('\n');
		i++;
	}
}

void	rush_x(int x, int y, int i)
{
	int	j;

	j = 0;
	while (j < x)
	{
		if ((i == 0 && j == 0) || (i == (y - 1) && j == 0))
			ft_putchar('A');
		else if ((i == 0 && j == (x - 1)) || (i == (y - 1) && j == (x - 1)))
			ft_putchar('C');
		else if (i == 0 || j == 0 || i == (y - 1) || j == (x - 1))
			ft_putchar('B');
		else
			ft_putchar(' ');
		j++;
	}
}			
