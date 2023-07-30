/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:44:41 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 16:21:00 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init(t_cub *cub, char *av)
{
	t_pts	pts;
	t_col	col;
	t_smap	*sma;

	cub->sma = NULL;
	cub->pts = &pts;
	cub->pts->no = NULL;
	cub->pts->so = NULL;
	cub->pts->we = NULL;
	cub->pts->ea = NULL;
	cub->col = &col;
	cub->col->cei = 0;
	cub->col->flo = 0;
	cub->map = NULL;
	cub->mlx = NULL;
	open_map(cub, av);
	read_map(cub);
	clean_map(cub, cub->sma);
	check_map(cub, cub->sma);
	printf("no[%s]\nso[%s]\nwe[%s]\nea[%s]\n", cub->pts->no, cub->pts->so, cub->pts->we, cub->pts->ea);
	printf("f[%x]\nc[%x]\n", cub->col->flo, cub->col->cei);
	sma = cub->sma;
	while (sma)
	{
		printf("map[%s]\n", sma->s);
		sma = sma->nxt;
	}
	free(cub->pts->no);
	free(cub->pts->so);
	free(cub->pts->we);
	free(cub->pts->ea);
}
