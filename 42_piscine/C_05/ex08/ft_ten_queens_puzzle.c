/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:09:47 by dseo              #+#    #+#             */
/*   Updated: 2022/01/19 21:14:45 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_ten_queens_puzzle(void);
int		promising(int idx);
int		ft_abs(int num);
void	queens(int idx);
void	print_chess(void);

int	g_col[10] = {0, };
int	g_cnt = 0;

int	ft_ten_queens_puzzle(void)
{
	queens(0);
	return (g_cnt);
}

int	promising(int idx)
{
	int	idx2;
	int	res;

	idx2 = 0;
	res = 1;
	while (idx2 < idx && res)
	{
		if (g_col[idx] == g_col[idx2]
			|| (ft_abs(g_col[idx] - g_col[idx2]) == idx - idx2))
			res = 0;
		idx2++;
	}
	return (res);
}

int	ft_abs(int num)
{
	if (num < 0)
		num = num * -1;
	return (num);
}

void	print_chess(void)
{
	int	i;
	int	locate;

	i = 0;
	while (i < 10)
	{
		locate = g_col[i] + '0';
		write(1, &locate, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	queens(int idx)
{
	int	i;

	if (promising(idx - 1))
	{
		if (idx == 10)
		{
			print_chess();
			g_cnt++;
			return ;
		}
		else
		{
			i = 0;
			while (i < 10)
			{
				g_col[idx] = i;
				queens(idx + 1);
				i++;
			}
		}
	}
}
