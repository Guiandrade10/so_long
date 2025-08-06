/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:54:41 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 16:17:48 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	validate_file(t_map *map)
{
	const char	*ext = ".ber";
	size_t		len;

	len = ft_strlen(map->filename);
	if (len < 5)
		map_filename_error();
	if (ft_strncmp(map->filename + len - 4, ext, 4) != 0)
		map_filename_error();
}

static void	validade_params(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->array[y][x] == 'C')
				map->c += 1;
			else if (map->array[y][x] == 'E')
				map->e += 1;
			else if (map->array[y][x] == 'P')
				map->p += 1;
			else if (map->array[y][x] == '0' || map->array[y][x] == '1')
				;
			else
				map_elements_error(map);
			x++;
		}
		y++;
	}
	if (map->c < 1 || map->e < 1 || map->p != 1)
		map_elements_error(map);
}

void	validate_map_rectangle(t_map *map)
{
	int		y;
	size_t	width;

	y = 0;
	width = ft_strlen(map->array[0]);
	while (y < map->y)
	{
		if (ft_strlen(map->array[y]) != width)
			map_size_error(map);
		y++;
	}
	map->x = width;
}

void	validate_map(t_map *map)
{
	validate_file(map);
	read_map_file(map);
	validate_map_rectangle(map);
	validate_wall(map);
	validade_params(map);
	validate_path(map);
	ft_free_array(map->copy, map->y);
}
