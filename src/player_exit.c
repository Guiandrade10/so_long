/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:32:35 by gude-and          #+#    #+#             */
/*   Updated: 2025/08/04 21:47:22 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_z(t_map *map, int x, int y)
{
	if (map->c == 0)
		print_all(map, x, y, map->img.exit_open);
	else
		print_all(map, x, y, map->img.exit_close);
	map->array[y][x] = 'E';
}

void	player_left(t_map *map, int x, int y)
{
	if (map->exit == 1)
		return ;
	map->moves++;
	print_all(map, x, y, map->img.empty);
	map->array[y][x] = '0';
	x--;
	print_moves(map);
	print_all(map, x, y, map->img.empty);
	print_all(map, x, y, map->img.px);
	map->array[y][x] = 'Z';
	map->player.x = x;
}

void	player_right(t_map *map, int x, int y)
{
	if (map->exit == 1)
		return ;
	map->moves++;
	print_all(map, x, y, map->img.empty);
	map->array[y][x] = '0';
	x++;
	print_moves(map);
	print_all(map, x, y, map->img.empty);
	print_all(map, x, y, map->img.px);
	map->array[y][x] = 'Z';
	map->player.x = x;
}

void	player_up(t_map *map, int x, int y)
{
	if (map->exit == 1)
		return ;
	map->moves++;
	print_all(map, x, y, map->img.empty);
	map->array[y][x] = '0';
	y--;
	print_moves(map);
	print_all(map, x, y, map->img.empty);
	print_all(map, x, y, map->img.px);
	map->array[y][x] = 'Z';
	map->player.y = y;
}

void	player_down(t_map *map, int x, int y)
{
	if (map->exit == 1)
		return ;
	map->moves++;
	print_all(map, x, y, map->img.empty);
	map->array[y][x] = '0';
	y++;
	print_moves(map);
	print_all(map, x, y, map->img.empty);
	print_all(map, x, y, map->img.px);
	map->array[y][x] = 'Z';
	map->player.y = y;
}
