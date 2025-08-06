/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:29:43 by gude-and          #+#    #+#             */
/*   Updated: 2025/08/04 20:46:26 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	render_tile(t_map *map, int x, int y)
{
	int	type;

	type = map->array[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.empty, x, y);
	if (type == 'C')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(map->mlx, map->wnd,
			map->img.player_down, x, y);
	else if (type == 'E')
	{
		if (map->c == 0)
			mlx_put_image_to_window(map->mlx, map->wnd,
				map->img.exit_open, x, y);
		else
			mlx_put_image_to_window(map->mlx, map->wnd,
				map->img.exit_close, x, y);
	}
	else if (type == '1')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.wall, x, y);
	else if (type == 'Z')
		mlx_put_image_to_window(map->mlx, map->wnd, map->img.px, x, y);
}

void	render_map(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			render_tile(map, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	print_all(t_map *map, int x, int y, void *image)
{
	mlx_put_image_to_window(map->mlx, map->wnd, image,
		x * IMG_PXL, y * IMG_PXL);
}

void	print_moves(t_map *map)
{
	char	*move;

	move = ft_itoa(map->moves);
	write(1, move, ft_strlen(move));
	write(1, " moves\n", 7);
	free(move);
}
