/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:27:47 by gude-and          #+#    #+#             */
/*   Updated: 2025/08/04 21:28:45 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	load_player_textures(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.player_right = mlx_xpm_file_to_image(map->mlx,
			"textures/right.xpm", &a, &a);
	map->img.player_up = mlx_xpm_file_to_image(map->mlx,
			"textures/up.xpm", &a, &a);
	map->img.player_down = mlx_xpm_file_to_image(map->mlx,
			"textures/down.xpm", &a, &a);
	map->img.player_left = mlx_xpm_file_to_image(map->mlx,
			"textures/left.xpm", &a, &a);
	map->img.px = mlx_xpm_file_to_image(map->mlx,
			"textures/player_dor.xpm", &a, &a);
	if (!map->img.px || !map->img.player_left || !map->img.player_down
		|| !map->img.player_up || !map->img.player_right)
	{
		write(2, "Load textures error\n", 21);
		ft_close(map);
	}
}

void	load_textures(t_map *map)
{
	int	a;

	a = IMG_PXL;
	map->img.empty = mlx_xpm_file_to_image(map->mlx,
			"textures/flor.xpm", &a, &a);
	map->img.wall = mlx_xpm_file_to_image(map->mlx,
			"textures/wall.xpm", &a, &a);
	map->img.exit_open = mlx_xpm_file_to_image(map->mlx,
			"textures/door.xpm", &a, &a);
	map->img.exit_close = mlx_xpm_file_to_image(map->mlx,
			"textures/closed.dor.xpm", &a, &a);
	map->img.collectible = mlx_xpm_file_to_image(map->mlx,
			"textures/key.xpm", &a, &a);
	load_player_textures(map);
	if (!map->img.empty || !map->img.wall || !map->img.exit_open
		|| !map->img.exit_close || !map->img.collectible)
	{
		write(2, "Load textures error\n", 21);
		ft_close(map);
	}
}
