/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validade_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:58:23 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 16:01:17 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	check_top_wall(t_map *map)
{
	int	x;

	x = 0;
	while (map->array[0][x])
	{
		if (map->array[0][x] != '1')
			wall_error(map);
		x++;
	}
}

static void	check_bottom_wall(t_map *map)
{
	int	x;

	x = 0;
	while (map->array[map->y - 1][x])
	{
		if (map->array[map->y - 1][x] != '1')
			wall_error(map);
		x++;
	}
}

static void	check_side_walls(t_map *map)
{
	int	y;

	y = 1;
	while (y < map->y - 1)
	{
		if (map->array[y][0] != '1'
			|| map->array[y][map->x - 1] != '1')
			wall_error(map);
		y++;
	}
}

void	validate_wall(t_map *map)
{
	check_top_wall(map);
	check_side_walls(map);
	check_bottom_wall(map);
}
