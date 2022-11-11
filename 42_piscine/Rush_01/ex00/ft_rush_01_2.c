/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_01_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:54:00 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/01/16 21:54:02 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_01_2.h"
#include <unistd.h>

int	g_conditions[4][9];
int	g_row_used[9][10];
int	g_col_used[9][10];
int	g_answer[9][9];
int	g_answer_cnt[1];
int	g_dr[4] = {1, -1, 0, 0};
int	g_dc[4] = {0, 0, 1, -1};

void	print_arr(int n)
{
	int		r;
	int		c;
	char	ch;

	r = 0;
	while (r < n)
	{
		c = 0;
		while (c < n)
		{
			ch = '0' + g_answer[r][c];
			write(1, &ch, 1);
			if (c != n - 1)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			c++;
		}
		r++;
	}
}

int	get_condition(int k, int c, int mode)
{
	if (mode == 0 || mode == 1)
		return (g_conditions[mode][c]);
	if (mode == 2 || mode == 3)
		return (g_conditions[mode][k]);
	return (0);
}

int	check_condition(int k, int c, int m, int n)
{
	int	i;
	int	cnt;
	int	max_value;

	i = 0;
	cnt = 0;
	max_value = 0;
	while (i < n)
	{
		if (g_answer[k + g_dr[m] * i][c + g_dc[m] * i] > max_value)
		{
			cnt += 1;
			max_value = g_answer[k + g_dr[m] * i][c + g_dc[m] * i];
		}
		i++;
	}
	if (cnt == get_condition(k, c, m))
		return (1);
	return (0);
}

int	check_row(int k, int n)
{
	if (!check_condition(k, 0, 2, n))
		return (0);
	if (!check_condition(k, n - 1, 3, n))
		return (0);
	return (1);
}

int	check_col(int c, int n)
{
	if (!check_condition(0, c, 0, n))
		return (0);
	if (!check_condition(n - 1, c, 1, n))
		return (0);
	return (1);
}
