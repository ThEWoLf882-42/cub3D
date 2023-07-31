/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:42:39 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 12:13:38 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	loop(void *par)
{
	t_cub	*cub;
	int		x;
	int		y;

	cub = par;
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mx->mlx);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y <= HEIGHT / 2)
				mlx_put_pixel(cub->mx->img, x, y, cub->col->cei);
			else
				mlx_put_pixel(cub->mx->img, x, y, cub->col->flo);
		}
	}
	x = 0;
	while (cub->map->map[x])
	{
		y = -1;
		while (cub->map->map[x][++y])
		{
			if (cub->map->map[x][y] == '1')
				mlx_put_pixel(cub->mx->img, y, x, 0xFFFFFFFF);
			else if (cub->map->map[x][y] == '0')
				mlx_put_pixel(cub->mx->img, y, x, 0x00000000);
		}
		x++;
	}
}
