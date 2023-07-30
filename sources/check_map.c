/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:39:39 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 19:49:12 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map(t_cub *cub, t_smap *sma)
{
	size_t	i;

	while (sma)
	{
		i = -1;
		while (sma->s[++i])
		{
			if (sma->s[i] == '0')
			{
				if (i - 1 < 0 && (!sma->s[i - 1] || sma->s[i - 1] == ' '))
					get_out_s(cub, "Invalid map\n");
				if (i + 1 > ft_strlen(sma->s)
					&& (!sma->s[i + 1] || sma->s[i + 1] == ' '))
					get_out_s(cub, "Invalid map\n");
				if (!sma->nxt || i > ft_strlen(sma->nxt->s)
					|| !sma->nxt->s[i] || sma->nxt->s[i] == ' ')
					get_out_s(cub, "Invalid map\n");
				if (!sma->prv || i > ft_strlen(sma->prv->s)
					|| !sma->prv->s[i] || sma->prv->s[i] == ' ')
					get_out_s(cub, "Invalid map\n");
			}
		}
		sma = sma->nxt;
	}
}