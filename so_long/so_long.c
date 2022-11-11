/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:31:55 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 21:16:12 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	*game;
	int		fd;

	if (argc != 2)
		error_print("Invalid argument\n");
	check_map_name(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error_print("File open fail");
	game = (t_game *)malloc(sizeof(t_game));
	game_init(game, fd);
	check_map(game);
	mlx_hook(game->mlx_win, KEY_PRESS, 0, &keypress_event, game);
	mlx_hook(game->mlx_win, KEY_EXIT, 0, &end_game, game);
	mlx_loop(game->mlx);
	return (0);
}

void	error_print(char *str)
{
	printf("%s", str);
	exit(1);
}

void	check_map_name(char *str)
{
	int	i;

	if (ft_strlen(str) < 4)
		error_print("Map isn't ber file");
	i = ft_strlen(str) - 4;
	if (str[i] != '.' || str[i + 1] != 'b' \
	|| str[i + 2] != 'e' || str[i + 3] != 'r')
		error_print("Map isn't ber file");
}

void	game_init(t_game *game, int fd)
{
	game->mlx = mlx_init();
	game->img = img_init(game->mlx);
	game->p_count = 0;
	game->c_count = 0;
	game->e_count = 0;
	game->point_count = 0;
	game->walk_count = 0;
	read_map(game, fd);
	game->mlx_win = mlx_new_window(game->mlx, game->width * 64 \
	, game->height * 64, "so_long");
	setting_img(game);
}

void	read_map(t_game *game, int fd)
{
	char	*buf;
	int		height;

	height = 1;
	buf = get_next_line(fd);
	read_map_line(game, buf, height);
	while (buf)
	{
		buf = get_next_line(fd);
		if (!buf)
			break ;
		height++;
		read_map_line(game, buf, height);
	}
	game->height = height;
	close(fd);
}
