/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:45:53 by agimi             #+#    #+#             */
/*   Updated: 2023/08/22 20:07:22 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	tot(void *par)
{
	t_cub				*cub;
	static mlx_image_t	*img;
	static int			s;
	static int			i;

	cub = par;
	mlx_delete_image(cub->mx->mlx, img);
	if (s % 3 == 0)
		i++;
	img = mlx_texture_to_image(cub->mx->mlx, cub->mx->tot[i]);
	mlx_image_to_window(cub->mx->mlx, img, 2290, 72);
	s++;
	if (i == 38)
		i = 0;
	if (s == 3 * 38)
		s = 0;
}
