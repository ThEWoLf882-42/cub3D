/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smap_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:43:08 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 12:12:28 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*map_xfa(t_smap *sma)
{
	char	*xfa;
	int		i;
	int		x;
	int		j;

	if (!sma || !sma->s)
		return (NULL);
	xfa = malloc(sizeof(char) * (ft_strlen(sma->s) * XFA) + 1);
	i = -1;
	j = 0;
	while (sma->s[++i])
	{
		x = XFA + 1;
		while (--x)
			xfa[j++] = sma->s[i];
	}
	xfa[j] = '\0';
	return (xfa);
}

void	smap_map(t_cub *cub)
{
	t_smap	*sma;
	char	**map;
	int		i;
	int		x;

	sma = cub->sma;
	i = ft_lstsize(sma) * XFA + 1;
	map = malloc(sizeof(char *) * i);
	if (!map)
		get_out_s(cub, "map alloc faild\n");
	i = 0;
	while (sma)
	{
		x = XFA + 1;
		while (--x)
			map[i++] = map_xfa(sma);
		sma = sma->nxt;
	}
	map[i] = NULL;
	cub->map->map = map;
}
