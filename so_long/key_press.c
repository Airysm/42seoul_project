/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 23:20:31 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 21:25:29 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keypress_event(int key, t_game *game)
{
	int	i;

	i = 0;
	if (key == ESC)
		end_game(game);
	if (key == A)
		i = -1;
	if (key == S)
		i = game->width;
	if (key == D)
		i = 1;
	if (key == W)
		i = -game->width;
	press_key(game, i);
	return (0);
}

int	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	exit(0);
}

void	press_key(t_game *game, int move)
{
	unsigned int	i;

	i = 0;
	if (move == 0)
		return ;
	while (i < ft_strlen(game->map))
	{
		if (game->map[i] == 'P')
			break ;
		i++;
	}
	if (game->map[i + move] == 'C')
		game->point_count += 1;
	if (game->map[i + move] == 'E' && game->c_count == game->point_count)
		clear_game(game);
	else if (game->map[i + move] != '1' && game->map[i + move] != 'E')
	{
		game->map[i] = '0';
		game->map[i + move] = 'P';
		game->walk_count += 1;
		printf("%d\n", game->walk_count);
		setting_img(game);
	}
}

void	clear_game(t_game *game)
{
	game->walk_count += 1;
	printf("%d walks\n", game->walk_count);
	exit(0);
}
