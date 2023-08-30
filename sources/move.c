/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 12:29:50 by agimi             #+#    #+#             */
/*   Updated: 2023/08/30 12:07:29 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mv_tst(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'D')
		return (0);
	return (1);
}

void	set_xy(t_cub *cub, char **map, double dx, double dy)
{
	if (mv_tst(map, cub->px + (dx * 2), cub->py)
		&& mv_tst(map, cub->px, cub->py + (dy * 2)))
	{
		cub->px += dx;
		cub->py += dy;
	}
}

void	c_r_m(t_cub *cub)
{
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mx->mlx);
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_LEFT))
		cub->pan -= RSTEP;
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_RIGHT))
		cub->pan += RSTEP;
	if (cub->pan > 2 * M_PI)
		cub->pan -= 2 * M_PI;
	if (cub->pan < 0)
		cub->pan += 2 * M_PI;
}

void	set_ds(double *dx, double *dy, double cpan, double span)
{
	*dx += cpan * MSTEP;
	*dy += span * MSTEP;
}

void	move(void *par)
{
	t_cub	*cub;
	char	**map;
	double	dx;
	double	dy;

	cub = par;
	map = cub->map->map;
	dx = 0.0;
	dy = 0.0;
	c_r_m(cub);
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_W))
		set_ds(&dx, &dy, cos(cub->pan), sin(cub->pan));
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_S))
		set_ds(&dx, &dy, -cos(cub->pan), -sin(cub->pan));
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_A))
		set_ds(&dx, &dy, cos(cub->pan - M_PI / 2.0),
			sin(cub->pan - M_PI / 2.0));
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_D))
		set_ds(&dx, &dy, -cos(cub->pan - M_PI / 2.0),
			-sin(cub->pan - M_PI / 2.0));
	set_xy(cub, map, dx, dy);
}
