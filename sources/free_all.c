/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 11:04:38 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/23 11:27:18 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_cub *cub)
{
	int	y;

	y = -1;
	clear_smap(&cub->sma);
	while (cub->map->map && cub->map->map[++y])
		free(cub->map->map[y]);
	free(cub->map->map);
	free(cub->mx->tno);
	free(cub->mx->tso);
	free(cub->mx->tea);
	free(cub->mx->twe);
	free(cub->mx->tdo);
}
