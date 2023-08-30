/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_coll_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:03:05 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/27 11:46:02 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	door_check(t_cub *cub, t_cas *cas, int i)
{
	if (cub->map->map[(int)(cas->ry[i] - cas->dy[i] * STEPS)]
		[(int)cas->rx[i]] == 'D')
		cas->side[i] = DOORH;
	if (cub->map->map[(int)cas->ry[i]]
		[(int)(cas->rx[i] - cas->dx[i] * STEPS)] == 'D')
		cas->side[i] = DOORV;
}

bool	wall_check(char **map, t_cas *cas, double ol_x, double ol_y)
{
	int	i;

	i = cas->i;
	if (map[(int)cas->ry[i]][(int)ol_x] == '1'
		&& map[(int)ol_y][(int)cas->rx[i]] == '1')
		return (true);
	return (false);
}
