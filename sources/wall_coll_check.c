/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_coll_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:03:05 by fbelahse          #+#    #+#             */
/*   Updated: 2023/08/23 13:29:42 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	wall_check(char **map, t_cas *cas, double ol_x, double ol_y)
{
	int	i;

	i = cas->i;
	if (map[(int)cas->ry[i]][(int)ol_x] == '1'
		&& map[(int)ol_y][(int)cas->rx[i]] == '1')
		return (true);
	return (false);
}
