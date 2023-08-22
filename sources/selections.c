/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selections.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:04:10 by agimi             #+#    #+#             */
/*   Updated: 2023/08/22 16:19:02 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	texture_select(t_cub *cub, t_cas *cas, t_text *text)
{
	if (cas->side[text->x] == TOP)
	{
		text->tex = cub->mx->twe;
		text->wid = cub->mx->we->width;
	}
	else if (cas->side[text->x] == BOTTOM)
	{
		text->tex = cub->mx->tea;
		text->wid = cub->mx->ea->width;
	}
	else if (cas->side[text->x] == RIGHT)
	{
		text->tex = cub->mx->tso;
		text->wid = cub->mx->so->width;
	}
	else if (cas->side[text->x] == LEFT)
	{
		text->tex = cub->mx->tno;
		text->wid = cub->mx->no->width;
	}
	else if (cas->side[text->x] == DOOR)
	{
		text->tex = cub->mx->tdo;
		text->wid = cub->mx->door->width;
	}
}

void	side_select(t_cub *cub, t_cas *cas, int i)
{
	(void)cub;
	if (cas->side[i] == LEFTRIGHT)
	{
		if ((cas->ang[i] > 0 && cas->ang[i] < M_PI) || cas->ang[i] >= 2 * M_PI)
			cas->side[i] = RIGHT;
		else
			cas->side[i] = LEFT;
	}
	else if (cas->side[i] == TOPBOTTOM)
	{
		if (cas->ang[i] > (0.5 * M_PI) && cas->ang[i] < (1.5 * M_PI))
			cas->side[i] = TOP;
		else
			cas->side[i] = BOTTOM;
	}
}
