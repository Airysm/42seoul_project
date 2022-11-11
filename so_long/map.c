/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 08:52:34 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 03:31:22 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map_line(t_game *game, char *buf, int height)
{
	int	width;

	width = ft_strlen_without_nl(buf);
	if (height == 1)
	{
		game->width = width;
		game->map = ft_strdup_without_nl(buf);
	}
	else
	{
		if (game->width != width)
			error_print("It's not square\n");
		game->map = ft_strjoin_without_nl(game->map, buf);
	}
	free(buf);
}

void	check_map(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		check_map_char(game, game->map[i], i);
		if (game->map[i] == 'E')
			game->e_count++;
		if (game->map[i] == 'P')
			game->p_count++;
		if (game->map[i] == 'C')
			game->c_count++;
		i++;
	}
	if (game->p_count != 1 || game->c_count < 1 || game->e_count < 1)
		error_print("Invalid  map\n");
}

void	check_map_char(t_game *game, char map, int i)
{
	if (map != '1' && map != '0' && map != 'E' && map != 'P' && map != 'C')
		error_print("Invalid character\n");
	if (i >= 0 && i < game->width)
	{
		if (game->map[i] != '1')
			error_print("First line must be fill with a wall\n");
	}
	else if (i >= game->width * (game->height - 1) \
		&& i < game->width * game->height)
	{
		if (game->map[i] != '1')
			error_print("Last line must be fill with a wall\n");
	}
	else if (i % game->width == 0 || i % game->width == game->width - 1)
	{
		if (game->map[i] != '1')
			error_print("First and last one must be a wall\n");
	}
}
