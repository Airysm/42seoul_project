/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonjan <hyeonjan@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 21:54:17 by hyeonjan          #+#    #+#             */
/*   Updated: 2022/01/18 13:00:51 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_rush_01_1.h"
#include "ft_rush_01_2.h"

extern int	g_conditions[4][9];
extern int	g_answer_cnt[1];

int	chk_invalid(int argc, char *argv[], int n)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (n < 1 || n > 9)
		return (0);
	if (argc != 2)
		return (0);
	while (argv[1][++i] != '\0')
	{
		if (argv[1][i] >= '1' && argv[1][i] <= n + '0')
		{
			j++;
			g_conditions[j / n][j % n] = argv[1][i] - '0';
		}
		else if (argv[1][i] != ' ')
			return (0);
	}
	if (++j != n * 4)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	int	n;

	n = 4;
	if (!(chk_invalid(argc, argv, n)))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	get_k_row(0, n);
	if (g_answer_cnt[0] == 0)
		write(1, "Error\n", 6);
}
