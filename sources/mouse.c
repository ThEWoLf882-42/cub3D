/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:50 by agimi             #+#    #+#             */
/*   Updated: 2023/08/26 11:06:59 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse(double x, double y, void *par)
{
	t_cub	*cub;

	(void)y;
	cub = par;
	mlx_set_mouse_pos(cub->mx->mlx, WIDTH / 2, HEIGHT / 2);
	mlx_set_cursor_mode(cub->mx->mlx, MLX_MOUSE_HIDDEN);
	cub->pan += (x - WIDTH / 2) / MSENS;
	if (cub->pan > 2 * M_PI)
		cub->pan -= 2 * M_PI;
	if (cub->pan < 0)
		cub->pan += 2 * M_PI;
}
