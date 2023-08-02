/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:06:57 by agimi             #+#    #+#             */
/*   Updated: 2023/08/02 10:32:14 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_column(t_cub *cub, t_cas *cas, int i)
{
	double	coh;
	double	hs;
	double	cow;
	int		x;
	int		y;

	coh = (16 * HEIGHT) / cas->dis;
	if (coh > HEIGHT)
		coh = HEIGHT;
	cow = WIDTH / NOR;
	hs = coh + (HEIGHT / 2 - (coh / 2));
	x = (i * cow) +  - 1;
	while (++x < i * cow)
	{
		y = HEIGHT / 2 - (coh / 2);
		while (++y < hs)
		{
			mlx_put_pixel(cub->mx->img, x, y, 0xFFFFFFFF);
		}
	}
}

void	draw_line(t_cub *cub, t_cas *cas)
{
	t_line	line;

	line.dx = cas->rx - cub->px;
	line.dy = cas->ry - cub->py;
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

void	cast(void *pra)
{
	t_cub	*cub;
	t_cas	cas;
	int		i;

	cub = pra;
	cas.sta = cub->pan - cub->fov / 2.0;
	cas.ani = cub->fov / NOR;
	i = -1;
	while (++i < NOR)
	{
		cas.ang = cas.sta + i * cas.ani;
		cas.dx = cos(cas.ang);
		cas.dy = sin(cas.ang);
		cas.rx = cub->px;
		cas.ry = cub->py;
		while (cub->map->map[(int)cas.ry][(int)cas.rx] != '1')
		{
			cas.rx += cas.dx * STEPS;
			cas.ry += cas.dy * STEPS;
			if (cas.rx < 0 || cas.rx >= WIDTH || cas.ry < 0 || cas.ry >= HEIGHT)
				break ;
		}
		cas.dis = sqrt((cas.rx - cub->px) * (cas.rx - cub->px)
				+ (cas.ry - cub->py) * (cas.ry - cub->py));
		draw_line(cub, &cas);
		draw_column(cub, &cas, i);
	}
}
