/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:06:57 by agimi             #+#    #+#             */
/*   Updated: 2023/08/23 17:49:14 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_column(t_cub *cub, t_cas *cas, int i)
{
	t_text	text;

	texture_select(cub, cas, &text);
	cas->dis[i] = sqrt((cas->rx[i] - cub->px) * (cas->rx[i] - cub->px)
			+ (cas->ry[i] - cub->py) * (cas->ry[i] - cub->py));
	cas->dis[i] = cas->dis[i] * cos(cas->ang[i] - cub->pan);
	text.coh = (16 * HEIGHT) / cas->dis[i];
	if (text.coh > HEIGHT)
		text.coh = HEIGHT;
	cas->hs = text.coh + (HEIGHT / 2 - (text.coh / 2));
	text.x = (i);
	text.y = HEIGHT / 2 - (text.coh / 2);
	text.yinc = (double)(cas->hs - text.y) / text.hei;
	text.idx = 0;
	while (text.idx < text.wid)
	{
		print_texture(cub, cas, &text);
		text.y += text.yinc;
		text.idx++;
	}
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
		if (cub->map->map[line.gy][line.gx] == '1'
			|| cub->map->map[line.gy][line.gx] == 'D')
			break ;
		mlx_put_pixel(cub->mx->img, (int)line.x, (int)line.y, 0x800080FF);
		line.x += line.xi;
		line.y += line.yi;
		line.ste--;
	}
}

void	mini_loop(t_cub *cub, t_cas *cas)
{
	int	i;

	i = cas->i;
	while (cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] != '1'
		&& cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] != 'D')
	{
		cas->rx[i] += cas->dx[i] * STEPS;
		if (cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] != '1')
			cas->side[i] = LEFTRIGHT;
		cas->ry[i] += cas->dy[i] * STEPS;
		if (cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] != '1')
			cas->side[i] = TOPBOTTOM;
		if (cub->map->map[(int)cas->ry[i]][(int)cas->rx[i]] == 'D')
			cas->side[i] = DOOR;
		if (cas->rx[i] < 0 || cas->rx[i] >= WIDTH
			|| cas->ry[i] < 0 || cas->ry[i] >= HEIGHT)
			break ;
		if (wall_check(cub->map->map, cas, cas->rx[i] - cas->dx[i] * STEPS,
				cas->ry[i] - cas->dy[i] * STEPS))
			break ;
	}
}

void	cast_loop(t_cub *cub, t_cas *cas)
{
	int	i;

	i = -1;
	while (++i < NOR)
	{
		cas->i = i;
		cas->ang[i] = cas->sta + i * cas->ani;
		cas->dx[i] = cos(cas->ang[i]);
		cas->dy[i] = sin(cas->ang[i]);
		cas->rx[i] = cub->px;
		cas->ry[i] = cub->py;
		mini_loop(cub, cas);
		side_select(cub, cas, i);
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
