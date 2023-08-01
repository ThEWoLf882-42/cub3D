/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:25 by agimi             #+#    #+#             */
/*   Updated: 2023/08/01 15:54:54 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_cub	cub;
	t_pts	pts;
	t_col	col;
	t_map	map;
	t_mlx	mx;

	if (ac == 2)
	{
		cub.pts = &pts;
		cub.col = &col;
		cub.map = &map;
		cub.mx = &mx;
		init(&cub, av[1]);
		mlx_cursor_hook(cub.mx->mlx, mouse, &cub);
		mlx_loop_hook(cub.mx->mlx, loop, &cub);
		mlx_loop_hook(cub.mx->mlx, move, &cub);
		mlx_loop_hook(cub.mx->mlx, cast, &cub);
		mlx_loop(cub.mx->mlx);
		mlx_terminate(cub.mx->mlx);
		clear_smap(&cub.sma);
		free(cub.pts->no);
		free(cub.pts->so);
		free(cub.pts->we);
		free(cub.pts->ea);
	}
	else
		ft_putstr_fd("Please Enter a .cub arg (only)\n", 2);
}
