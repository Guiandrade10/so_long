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

static void	move_resume(t_map *map, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	render_map(map);
	if (map->array[y][x] == 'E' && map->c == 0)
		return (ft_win(map));
	if (map->array[y][x] == 'C')
	{
		map->array[y][x] = '0';
		map->c--;
		render_map(map);
	}
}

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y > 0 && map->array[y - 1][x] != '1')
	{
		move_resume(map, x, y, UP);
		if (map->array[y - 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (player_up(map, x, y));
		map->moves++;
		print_all(map, x, y, map->img.empty);
		if (map->array[y][x] == 'Z')
			player_z(map, x, y);
		else
			map->array[y][x] = '0';
		y--;
		print_moves(map);
		print_all(map, x, y, map->img.empty);
		print_all(map, x, y, map->img.player_up);
		map->array[y][x] = 'P';
		map->player.x = x;
	}
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x > 0 && map->array[y][x - 1] != '1')
	{
		move_resume(map, x, y, LEFT);
		if (map->array[y][x - 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (player_left(map, x, y));
		map->moves++;
		print_all(map, x, y, map->img.empty);
		if (map->array[y][x] == 'Z')
		{
			player_z(map, x, y);
		}
		else
			map->array[y][x] = '0';
		x--;
		print_moves(map);
		print_all(map, x, y, map->img.empty);
		print_all(map, x, y, map->img.player_left);
		map->array[y][x] = 'P';
		map->player.y = y;
	}
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (y < map->y && map->array[y + 1][x] != '1')
	{
		move_resume(map, x, y, DOWN);
		if (map->array[y + 1][x] == 'E' && (map->c != 0 || map->exit == 1))
			return (player_down(map, x, y));
		map->moves++;
		print_all(map, x, y, map->img.empty);
		if (map->array[y][x] == 'Z')
			player_z(map, x, y);
		else
			map->array[y][x] = '0';
		y++;
		print_all(map, x, y, map->img.empty);
		print_all(map, x, y, map->img.player_down);
		map->array[y][x] = 'P';
		print_moves(map);
		map->player.y = y;
	}
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y;
	if (x < map->x && map->array[y][x + 1] != '1')
	{
		move_resume(map, x, y, RIGHT);
		if (map->array[y][x + 1] == 'E' && (map->c != 0 || map->exit == 1))
			return (player_right(map, x, y));
		map->moves++;
		print_all(map, x, y, map->img.empty);
		if (map->array[y][x] == 'Z')
			player_z(map, x, y);
		else
			map->array[y][x] = '0';
		x++;
		print_all(map, x, y, map->img.empty);
		print_all(map, x, y, map->img.player_right);
		map->array[y][x] = 'P';
		print_moves(map);
	}
	map->player.x = x;
}
