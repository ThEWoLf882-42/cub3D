/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:14:32 by agimi             #+#    #+#             */
/*   Updated: 2023/08/24 14:55:37 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_texture(t_cub *cub, t_cas *cas, t_text *text)
{
	int		xt;
	int		i;
	float	tmp;

	if (cas->side[text->x] == TOP || cas->side[text->x] == BOTTOM)
		xt = (int)(cas->ry[text->x] * (text->wid / XFA)) % text->wid;
	else
		xt = (int)(cas->rx[text->x] * (text->wid / XFA)) % text->wid;
	tmp = text->y ;
	while (tmp < text->y + text->yinc)
	{
		i = text->idx * text->wid + xt;
		mlx_put_pixel(cub->mx->img, text->x, tmp, text->tex[i]);
		tmp++;
	}
}
