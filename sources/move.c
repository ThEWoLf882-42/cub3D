/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:34:20 by agimi             #+#    #+#             */
/*   Updated: 2023/08/01 11:53:32 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mv_tst(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (0);
	return (1);
}

void move(void *par)
{
    t_cub *cub = par;
    char **map = cub->map->map;
    double move_step = 1.5; // Adjust the movement step size according to your needs.
    double rotate_step = M_PI / 36.0; // Adjust the rotation step size according to your needs.

    if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(cub->mx->mlx);

    // Rotate the player's direction
    if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_LEFT))
        cub->pan -= rotate_step;
    if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_RIGHT))
        cub->pan += rotate_step;
    // Movement direction flags
    bool move_forward = mlx_is_key_down(cub->mx->mlx, MLX_KEY_W);
    bool move_backward = mlx_is_key_down(cub->mx->mlx, MLX_KEY_S);
    bool strafe_left = mlx_is_key_down(cub->mx->mlx, MLX_KEY_A);
    bool strafe_right = mlx_is_key_down(cub->mx->mlx, MLX_KEY_D);

    // Calculate the new player position based on the movement direction
    double dx = 0.0;
    double dy = 0.0;

    if (move_forward)
    {
        dx += cos(cub->pan) * move_step;
        dy += sin(cub->pan) * move_step;
    }
    if (move_backward)
    {
        dx -= cos(cub->pan) * move_step;
        dy -= sin(cub->pan) * move_step;
    }

    // Calculate the strafe direction (left or right) relative to the player's orientation
    double strafe_angle = cub->pan - M_PI / 2.0;
    if (strafe_left)
    {
        dx += cos(strafe_angle) * move_step;
        dy += sin(strafe_angle) * move_step;
    }
    if (strafe_right)
    {
        dx -= cos(strafe_angle) * move_step;
        dy -= sin(strafe_angle) * move_step;
    }

    // Check if the new position is valid
    if (mv_tst(map, cub->px + dx, cub->py) && mv_tst(map, cub->px, cub->py + dy))
    {
        cub->px += dx;
        cub->py += dy;
    }

    mlx_put_pixel(cub->mx->img, cub->px, cub->py, 0x00FF00FF);
}
