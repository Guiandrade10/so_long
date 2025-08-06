/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:34:29 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 17:14:28 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_filename_error(void)
{
	write(2, "Error\nThe file must end with .ber\n", 34);
	exit(EXIT_FAILURE);
}

void	wall_error(t_map *map)
{
	write(2, "Error\nInvalid wall\n", 19);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	openfile_error(void)
{
	write(2, "Error\nFailed open\n", 18);
	exit(EXIT_FAILURE);
}

void	map_size_error(t_map *map)
{
	write(2, "Error\nMap is not rectangular.\n", 30);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}

void	map_elements_error(t_map *map)
{
	write(2, "Error\nInvalid map elements\n", 27);
	ft_free_array(map->array, map->y);
	ft_free_array(map->copy, map->y);
	exit(EXIT_FAILURE);
}
