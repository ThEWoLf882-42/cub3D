/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 21:42:39 by agimi             #+#    #+#             */
/*   Updated: 2023/08/24 14:53:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	flo_cei(void *par)
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
}

void	loop(t_cub *cub)
{
	int		x;
	int		y;

	y = 0;
	while (cub->map->map[y] && y <= HEIGHT)
	{
		x = -1;
		while (cub->map->map[y][++x])
		{
			if (x > WIDTH)
				break ;
			if (cub->map->map[y][x] == '1')
				mlx_put_pixel(cub->mx->img, x, y, 0xFFFFFFFF);
			else if (cub->map->map[y][x] == '0' || cub->map->map[y][x] == 'L')
				mlx_put_pixel(cub->mx->img, x, y, 0x00000000);
			else if (cub->map->map[y][x] == 'D')
				mlx_put_pixel(cub->mx->img, x, y, 0x0005E1FF);
		}
		y++;
	}
}
