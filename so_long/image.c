/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:06:46 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 03:31:49 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	img;
	int		w;
	int		h;

	img.player = mlx_xpm_file_to_image(mlx, "./images/player.xpm", &w, &h);
	img.empty = mlx_xpm_file_to_image(mlx, "./images/empty.xpm", &w, &h);
	img.wall = mlx_xpm_file_to_image(mlx, "./images/wall.xpm", &w, &h);
	img.end = mlx_xpm_file_to_image(mlx, "./images/end.xpm", &w, &h);
	img.item = mlx_xpm_file_to_image(mlx, "./images/item.xpm", &w, &h);
	return (img);
}

void	setting_img(t_game *game)
{
	int	height;
	int	width;

	height = 0;
	while (height < game->height)
	{
		width = 0;
		while (width < game->width)
		{
			put_img(game, width, height, game->width);
			width++;
		}
		height++;
	}
}

void	put_img(t_game *game, int w, int h, int width)
{
	char	map_char;

	map_char = game->map[width * h + w];
	if (map_char == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.wall, w * 64, h * 64);
	else if (map_char == 'C')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.item, w * 64, h * 64);
	else if (map_char == 'P')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.player, w * 64, h * 64);
	else if (map_char == 'E')
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.end, w * 64, h * 64);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
			game->img.empty, w * 64, h * 64);
}
