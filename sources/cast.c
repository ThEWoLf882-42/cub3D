/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:06:57 by agimi             #+#    #+#             */
/*   Updated: 2023/08/01 12:40:05 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_line(t_cub *cub, double x1, double y1, double x2, double y2)
{
    double dx = x2 - x1;
    double dy = y2 - y1;
    double steps = fmax(fabs(dx), fabs(dy));
    double x_inc = dx / steps;
    double y_inc = dy / steps;
    double x = x1;
    double y = y1;

    while (steps >= 0)
    {
        int grid_x = (int)floor(x);
        int grid_y = (int)floor(y);
        if (cub->map->map[grid_y][grid_x] == '1')
            break;
        mlx_put_pixel(cub->mx->img, (int)x, (int)y, 0x800080FF);
        x += x_inc;
        y += y_inc;
        steps--;
    }
}

void	cast(void *pra)
{
	t_cub	*cub;
	
	cub = pra;
    double step_size = 10; // Adjust the step size according to your needs.

    double start_angle = cub->pan - cub->fov / 2.0;
    double angle_increment = cub->fov / NOR;

    for (int i = 0; i < NOR; i++)
    {
        double angle = start_angle + i * angle_increment;

        double dx = cos(angle);
        double dy = sin(angle);

        double ray_x = cub->px;
        double ray_y = cub->py;

        while (cub->map->map[(int)ray_y][(int)ray_x] != '1')
        {
            // Move the ray in the direction of dx and dy.
            ray_x += dx * step_size;
            ray_y += dy * step_size;
            if (ray_x < 0 || ray_x >= WIDTH || ray_y < 0 || ray_y >= HEIGHT)
                break;
        }
        draw_line(cub, cub->px, cub->py, ray_x, ray_y);
    }

}
