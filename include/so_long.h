/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:44:16 by gude-and          #+#    #+#             */
/*   Updated: 2025/08/04 21:29:31 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../Libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define UP      119
# define DOWN    115
# define LEFT    97
# define RIGHT   100
# define ESC     65307
# define IMG_PXL 60
# define WND_NAME "so_long"

typedef struct s_player
{
	int	y;
	int	x;

}	t_player;

typedef struct s_img
{
	void	*empty;
	void	*collectible;
	void	*wall;
	void	*exit_open;
	void	*exit_close;
	void	*player_left;
	void	*player_right;
	void	*player_up;
	void	*player_down;
	void	*px;
}	t_img;

typedef struct s_map
{
	int			fd;
	char		*line;
	char		*file;
	char		**array;
	char		**copy;
	char		*filename;
	int			y;
	int			x;
	int			e;
	int			c;
	int			c_check;
	int			e_check;
	int			p;
	int			exit;
	int			moves;
	void		*mlx;
	void		*wnd;
	t_img		img;
	t_player	player;

}	t_map;

void	validate_map(t_map *map);
void	validate_wall(t_map *map);
void	read_map_file(t_map *map);
void	load_textures(t_map *map);
void	render_map(t_map *map);
int		key_hook(int keycode, t_map *map);

void	player_left(t_map *map, int x, int y);
void	player_right(t_map *map, int x, int y);
void	player_down(t_map *map, int x, int y);
void	player_up(t_map *map, int x, int y);
void	player_z(t_map *map, int x, int y);
void	print_all(t_map *map, int x, int y, void *image);

void	map_filename_error(void);
void	wall_error(t_map *map);
void	openfile_error(void);
void	map_size_error(t_map *map);

void	map_elements_error(t_map *map);
void	error_empty_line(t_map *map);
void	error_struct(void);

int		ft_free(char **ret, int i);
void	ft_exit_free(t_map *map);
int		ft_free_array(char **ret, int i);

void	move_up(t_map *map);
void	move_left(t_map *map);
void	move_down(t_map *map);
void	move_right(t_map *map);

void	ft_win(t_map *map);
int		ft_close(t_map *map);

void	print_moves(t_map *map);

void	validate_path(t_map *map);
void	locate_player(t_map *map);

#endif
