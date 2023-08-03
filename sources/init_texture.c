/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:39:37 by agimi             #+#    #+#             */
/*   Updated: 2023/08/03 09:55:22 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_texture(t_cub *cub)
{
	cub->mx->no = mlx_load_png(cub->pts->no);
	cub->mx->so = mlx_load_png(cub->pts->so);
	cub->mx->ea = mlx_load_png(cub->pts->ea);
	cub->mx->we = mlx_load_png(cub->pts->we);
	if (!cub->mx->no || !cub->mx->so || !cub->mx->ea || !cub->mx->we)
		get_out_s(cub, (char *)mlx_strerror(mlx_errno));
}
