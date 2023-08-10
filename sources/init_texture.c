/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:39:37 by agimi             #+#    #+#             */
/*   Updated: 2023/08/04 16:11:36 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*text_arr(mlx_texture_t *tex)
{
	int				*ar;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	ar = malloc(sizeof(int) * (tex->height * tex->width));
	while (i < (tex->width * tex->height) * tex->bytes_per_pixel)
	{
		ar[j++] = get_rgba(tex->pixels[i], tex->pixels[i + 1],
				tex->pixels[i + 2], tex->pixels[i + 3]);
		i += tex->bytes_per_pixel;
	}
	return (ar);
}

void	init_texture(t_cub *cub)
{
	cub->mx->no = mlx_load_png(cub->pts->no);
	cub->mx->so = mlx_load_png(cub->pts->so);
	cub->mx->ea = mlx_load_png(cub->pts->ea);
	cub->mx->we = mlx_load_png(cub->pts->we);
	if (!cub->mx->no || !cub->mx->so || !cub->mx->ea || !cub->mx->we)
		get_out_s(cub, (char *)mlx_strerror(mlx_errno));
	cub->mx->tno = text_arr(cub->mx->no);
	cub->mx->tso = text_arr(cub->mx->so);
	cub->mx->tea = text_arr(cub->mx->ea);
	cub->mx->twe = text_arr(cub->mx->we);
}