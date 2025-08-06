/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:34:01 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 18:19:43 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	locate_player(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'P' || map->array[y][x] == 'Z')
			{
				map->player.y = y;
				map->player.x = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	key_hook(int keycode, t_map *map)
{
	locate_player(map);
	if (keycode == ESC)
		return (ft_close(map));
	else if (map->exit == 1)
		return (0);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == DOWN)
		move_down(map);
	else if (keycode == RIGHT)
		move_right(map);
	else if (keycode == UP)
		move_up(map);
	return (0);
}
