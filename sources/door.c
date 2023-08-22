/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:32 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/22 18:27:26 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void back(t_cub *cub)
{
	int x;
	int y;
	int i;

	y = cub->py - 24.0;
	i = 0;
	if (y < 0)
		y = -1;
	while (++y < cub->py + 24.0)
	{
		x = cub->px - 24.0;
		if (x < 0)
			x = -1;
		while (++x < cub->px + 24.0)
			if (cub->map->map[(int)y][(int)x] == 'L')
				i = 1;
	}
	y = -1;
	while (cub->map->map[++y] && !i)
	{
		x = -1;
		while(cub->map->map[y][++x])
			if (cub->map->map[y][x] == 'L')
				cub->map->map[y][x] = 'D';
	}
}

void door(void *par)
{
	t_cub	*cub;
	double	x;
	double	y;

	cub = par;
	y = cub->py - 27.0;
	if (y < 0)
		y = -1;
	back(cub);
	if (mlx_is_key_down(cub->mx->mlx, MLX_KEY_O))
	{
		while (++y < cub->py + 27.0)
		{
			x = cub->px - 27.0;
			if (x < 0)
				x = -1;
			while (++x < cub->px + 27.0)
				if (cub->map->map[(int)y][(int)x] == 'D')
					cub->map->map[(int)y][(int)x] = 'L';
		}
	}
}
