/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:44:41 by agimi             #+#    #+#             */
/*   Updated: 2023/08/22 18:44:20 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_pts(t_cub *cub)
{
	cub->pts->no = NULL;
	cub->pts->so = NULL;
	cub->pts->we = NULL;
	cub->pts->ea = NULL;
}

void	init_col(t_cub *cub)
{
	cub->col->cei = 0;
	cub->col->flo = 0;
}

void	init_sma(t_cub *cub, char *av)
{
	cub->sma = NULL;
	open_map(cub, av);
	read_map(cub);
	clean_map(cub, cub->sma);
	check_map(cub, cub->sma);
}

void	init_mx(t_cub *cub)
{
	cub->mx->mlx = mlx_init(WIDTH, HEIGHT, "cube3D", false);
	cub->mx->img = mlx_new_image(cub->mx->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(cub->mx->mlx, cub->mx->img, 0, 0);
}

void	init(t_cub *cub, char *av)
{
	cub->fov = M_PI / 3.0;
	cub->px = 0;
	cub->py = 0;
	init_pts(cub);
	init_col(cub);
	init_sma(cub, av);
	smap_map(cub);
	init_texture(cub);
	init_mx(cub);
}
