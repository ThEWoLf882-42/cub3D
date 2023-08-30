/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:32 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/27 08:55:21 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	l_to_d(char **map, int i)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y] && !i)
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == 'L')
				map[y][x] = 'D';
	}
}

void	back(t_cub *cub, char **map)
{
	int	x;
	int	y;
	int	i;

	y = cub->py - 27.0;
	i = 0;
	if (y < 0)
		y = -1;
	while (++y < cub->py + 27.0)
	{
		x = cub->px - 27.0;
		if (x < 0)
			x = -1;
		while (++x < cub->px + 27.0)
			if (y < cub->map->he
				&& x < ft_strlen(map[(int)y]) && map[(int)y][(int)x] == 'L')
				i = 1;
	}
	l_to_d(map, i);
}

void	door(void *par)
{
	t_cub	*cub;
	double	x;
	double	y;

	cub = par;
	y = cub->py - 27.0;
	if (y < 0)
		y = -1;
	back(cub, cub->map->map);
	if (mlx_is_mouse_down(cub->mx->mlx, MLX_MOUSE_BUTTON_LEFT))
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
