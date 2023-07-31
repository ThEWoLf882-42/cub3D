/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 13:03:34 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 10:49:27 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	trim_space(t_smap *smap)
{
	t_smap	*tsma;
	t_smap	*sma;

	sma = smap;
	while (sma)
	{
		if (sma->nxt && sma->nxt->nxt
			&& ft_sisspace(sma->nxt->s) && ft_sisspace(sma->nxt->nxt->s))
		{
			tsma = sma->nxt;
			sma->nxt = sma->nxt->nxt;
			free(tsma->s);
			free(tsma);
		}
		else
			sma = sma->nxt;
	}
}

void	clean_map(t_cub *cub, t_smap *smap)
{
	t_smap	*tsma;

	if (!smap || !cub->col->cei || !cub->col->flo || !cub->pts->no
		|| !cub->pts->so || !cub->pts->ea || !cub->pts->we)
		get_out_s(cub, "Map Element missing\n");
	trim_space(smap);
	if (smap->nxt && ft_sisspace(ft_lstblast_m(smap)->nxt->s))
	{
		tsma = ft_lstblast_m(smap)->nxt;
		free(tsma->s);
		free(tsma);
		ft_lstblast_m(smap)->nxt = NULL;
	}
	while (smap)
	{
		if (ft_sisspace(smap->s))
			get_out_s(cub, "Check the map.\n");
		smap = smap->nxt;
	}
}
