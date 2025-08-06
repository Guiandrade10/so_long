/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:44:00 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 18:01:18 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	setup_map(t_map *map, char **argv)
{
	ft_bzero(map, sizeof(t_map));
	map->filename = argv[1];
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
	{
		write(2, "Please run with a map file: ./so_long maps/map.ber\n", 52);
		exit(EXIT_FAILURE);
	}
	else
	{
		setup_map(&map, argv);
		validate_map(&map);
		map.mlx = mlx_init();
		if (!map.mlx)
			return (EXIT_FAILURE);
		map.wnd = mlx_new_window(map.mlx,
				map.x * IMG_PXL, map.y * IMG_PXL, WND_NAME);
		if (!map.wnd)
			return (EXIT_FAILURE);
		load_textures(&map);
		render_map(&map);
		mlx_hook(map.wnd, 17, 0, ft_close, &map);
		mlx_key_hook(map.wnd, key_hook, &map);
		mlx_loop(map.mlx);
	}
}
