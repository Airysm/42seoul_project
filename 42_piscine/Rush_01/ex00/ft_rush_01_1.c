/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush_01_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:53:47 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/01/16 21:53:49 by hyeonjan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rush_01_1.h"
#include "ft_rush_01_2.h"

extern int	g_conditions[9][9];
extern int	g_row_used[9][10];
extern int	g_col_used[9][10];
extern int	g_answer[9][9];
extern int	g_answer_cnt[1];
extern int	g_dr[4];
extern int	g_dc[4];

void	get_k_c_num(int k, int c, int n)
{
	int	i;
	int	number;

	if (c == n)
	{
		if (check_row(k, n))
			get_k_row(k + 1, n);
		return ;
	}
	i = 1;
	number = 1;
	while (number <= n)
	{
		if (!g_row_used[k][number] && !g_col_used[c][number])
		{
			g_row_used[k][number] = 1;
			g_col_used[c][number] = 1;
			g_answer[k][c] = number;
			get_k_c_num(k, c + 1, n);
			g_row_used[k][number] = 0;
			g_col_used[c][number] = 0;
			g_answer[k][c] = 0;
		}
		number++;
	}
}

void	get_k_row(int k, int n)
{
	int	c;

	if (k == n)
	{
		c = 0;
		while (c < n)
		{
			if (!check_col(c, n))
				return ;
			c++;
		}
		print_arr(n);
		g_answer_cnt[0] += 1;
		return ;
	}
	get_k_c_num(k, 0, n);
}
