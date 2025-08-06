/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:57:56 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 17:12:41 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	read_map_file(t_map *map)
{
	int		fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	if (fd == -1)
		openfile_error();
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			break ;
		map->file = ft_strjoin(map->file, map->line);
		free(map->line);
		if (!map->file)
			ft_exit_free(map);
		map->y++;
	}
	close(fd);
	map->array = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->array || !map->copy)
		ft_exit_free(map);
	free(map->file);
}
