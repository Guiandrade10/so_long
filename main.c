/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-and <gude-and@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 16:22:15 by gude-and          #+#    #+#             */
/*   Updated: 2025/07/11 17:47:26 by gude-and         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int handle_keypress(int keycode, void *param)
{
    if (keycode == 65307)
    {
        void **mlx_win = (void **)param;
        mlx_destroy_window(mlx_win[0], mlx_win[1]); // fecha a janela
        exit(0); // encerra o programa
    }
    return 0;
}

int main(void)
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 640, 480, "Minha Janela");
    void *mlx_win[2] = {mlx, win};
    mlx_key_hook(win, handle_keypress, mlx_win);
    
    mlx_loop(mlx);
    return 0;
}