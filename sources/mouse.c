/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:49:50 by agimi             #+#    #+#             */
/*   Updated: 2023/08/30 15:48:52 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse(double x, double y, void *par)
{
	t_cub	*cub;

	(void)y;
	cub = par;
	mlx_set_cursor_mode(cub->mx->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(cub->mx->mlx, WIDTH / 2, HEIGHT / 2);
	cub->pan += (x - WIDTH / 2) / MSENS;
	if (cub->pan > 2 * M_PI)
		cub->pan -= 2 * M_PI;
	if (cub->pan < 0)
		cub->pan += 2 * M_PI;
}
