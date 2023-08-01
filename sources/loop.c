/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:42:39 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 14:39:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	loop(void *par)
{
	t_cub	*cub;
	int		x;
	int		y;

	cub = par;
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
	y = 0;
	while (cub->map->map[y])
	{
		x = -1;
		while (cub->map->map[y][++x])
		{
			if (cub->map->map[y][x] == '1')
				mlx_put_pixel(cub->mx->img, x, y, 0xFFFFFFFF);
			else if (cub->map->map[y][x] == '0')
				mlx_put_pixel(cub->mx->img, x, y, 0x00000000);
		}
		y++;
	}
}
