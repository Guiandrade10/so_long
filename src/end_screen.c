/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_screen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 14:35:29 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/27 18:10:36 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_img(t_map *map, void **img)
{
	if (*img)
	{
		mlx_destroy_image(map->mlx, *img);
		*img = NULL;
	}
}

int	ft_close(t_map *map)
{
	free_img(map, &map->img.collectible);
	free_img(map, &map->img.wall);
	free_img(map, &map->img.exit_open);
	free_img(map, &map->img.exit_close);
	free_img(map, &map->img.player_left);
	free_img(map, &map->img.player_right);
	free_img(map, &map->img.player_up);
	free_img(map, &map->img.player_down);
	free_img(map, &map->img.px);
	free_img(map, &map->img.empty);
	mlx_destroy_window(map->mlx, map->wnd);
	mlx_destroy_display(map->mlx);
	mlx_loop_end(map->mlx);
	free(map->mlx);
	ft_free_array(map->array, map->y);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_win(t_map *map)
{
	map->exit = 1;
	map->moves++;
	mlx_clear_window(map->mlx, map->wnd);
	write(1, "You won!\n", 10);
	ft_close(map);
}
