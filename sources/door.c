/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:25:32 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/27 11:33:17 by agimi            ###   ########.fr       */
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

	y = cub->py - (XFA + ((int)cub->py % XFA));
	i = 0;
	if (y < 0)
		y = -1;
	while (++y < cub->py + (XFA + ((int)cub->py % XFA)))
	{
		x = cub->px - (XFA + ((int)cub->px % XFA));
		if (x < 0)
			x = -1;
		while (++x < cub->px + (XFA + ((int)cub->px % XFA)))
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
	y = cub->py - (XFA + ((int)cub->py % XFA));
	if (y < 0)
		y = -1;
	back(cub, cub->map->map);
	if (mlx_is_mouse_down(cub->mx->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		while (++y < cub->py + (XFA + ((int)cub->py % XFA)))
		{
			x = cub->px - (XFA + ((int)cub->px % XFA));
			if (x < 0)
				x = -1;
			while (y < cub->map->he
				&& ++x < cub->px + (XFA + ((int)cub->px % XFA)))
				if (cub->map->map[(int)y][(int)x] == 'D')
					cub->map->map[(int)y][(int)x] = 'L';
		}
	}
}
