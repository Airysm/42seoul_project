/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseo <dseo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:32:05 by dseo              #+#    #+#             */
/*   Updated: 2022/10/19 21:15:41 by dseo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "get_next_line.h"

# define KEY_PRESS	2
# define KEY_EXIT	17
# define ESC		53
# define W			13
# define A			0
# define S			1
# define D			2

typedef struct s_img
{
	void	*player;
	void	*empty;
	void	*end;
	void	*item;
	void	*wall;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		width;
	int		height;
	int		p_count;
	int		e_count;
	int		c_count;
	int		point_count;
	int		walk_count;
	char	*map;
	t_img	img;
}	t_game;

void	error_print(char *str);
void	check_map_name(char *str);
void	game_init(t_game *game, int fd);
void	read_map(t_game *game, int fd);
void	read_map_line(t_game *game, char *buf, int height);
void	check_map(t_game *game);
void	check_map_char(t_game *game, char map, int i);
int		keypress_event(int key, t_game *game);
int		end_game(t_game *game);
void	press_key(t_game *game, int move);
void	clear_game(t_game *game);
void	setting_img(t_game *game);
void	put_img(t_game *game, int w, int h, int w_max);
t_img	img_init(void *mlx);
size_t	ft_strlen_without_nl(const char *s);
size_t	ft_strlcpy_without_nl(char *dst, const char *src, \
	size_t dstsize);
size_t	ft_strlcat_without_nl(char *dst, const char *src, size_t dstsize);
char	*ft_strdup_without_nl(const char *s1);
char	*ft_strjoin_without_nl(char *s1, char *s2);
#endif