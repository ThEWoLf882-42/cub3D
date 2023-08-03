/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:06:57 by agimi             #+#    #+#             */
/*   Updated: 2023/08/03 09:14:47 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_column(t_cub *cub, t_cas *cas, int i)
{
	double	coh;
	double	hs;
	int		x;
	int		y;

	coh = (16 * HEIGHT) / cas->dis[i];
	if (coh > HEIGHT)
		coh = HEIGHT;
	hs = coh + (HEIGHT / 2 - (coh / 2));
	x = (i);
		y = HEIGHT / 2 - (coh / 2);
	while (++y < hs)
		mlx_put_pixel(cub->mx->img, x, y, 0xDC143CA5);
}

void	draw_line(t_cub *cub, t_cas *cas, int i)
{
	t_line	line;

	line.dx = cas->rx[i] - cub->px;
	line.dy = cas->ry[i] - cub->py;
	line.ste = fmax(fabs(line.dx), fabs(line.dy));
	line.xi = line.dx / line.ste;
	line.yi = line.dy / line.ste;
	line.x = cub->px;
	line.y = cub->py;
	while (line.ste >= 0)
	{
		line.gx = (int)floor(line.x);
		line.gy = (int)floor(line.y);
		if (cub->map->map[line.gy][line.gx] == '1')
			break ;
		mlx_put_pixel(cub->mx->img, (int)line.x, (int)line.y, 0x800080FF);
		line.x += line.xi;
		line.y += line.yi;
		line.ste--;
	}
}

void	cast_loop(t_cub *cub, t_cas *cas)
{
	int	i;

	i = -1;
	while (++i < NOR)
	{
		cas->ang[i] = cas->sta + i * cas->ani;
		cas->dx[i] = cos(cas->ang[i]);
		cas->dy[i] = sin(cas->ang[i]);
		cas->rx[i] = cub->px;
		cas->ry[i] = cub->py;
		while (cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] != '1')
		{
			cas->rx[i] += cas->dx[i] * STEPS;
			cas->ry[i] += cas->dy[i] * STEPS;
			if (cas->rx[i] < 0 || cas->rx[i] >= WIDTH
				|| cas->ry[i] < 0 || cas->ry[i] >= HEIGHT)
				break ;
		}
		cas->dis[i] = sqrt((cas->rx[i] - cub->px) * (cas->rx[i] - cub->px)
				+ (cas->ry[i] - cub->py) * (cas->ry[i] - cub->py));
		cas->dis[i] = cas->dis[i] * cos(cas->ang[i] - cub->pan);
		draw_column(cub, cas, i);
	}
}

void	cast(void *pra)
{
	t_cub	*cub;
	t_cas	cas;
	int		i;

	cub = pra;
	cas.sta = cub->pan - cub->fov / 2.0;
	cas.ani = cub->fov / NOR;
	cast_loop(cub, &cas);
	i = -1;
	loop(cub);
	while (++i < NOR)
		draw_line(cub, &cas, i);
}
