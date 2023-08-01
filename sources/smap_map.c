/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smap_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:43:08 by agimi             #+#    #+#             */
/*   Updated: 2023/08/01 12:03:31 by agimi            ###   ########.fr       */
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
		{
			if (ft_isplayer(sma->s[i]))
				xfa[j++] = '0';
			else
				xfa[j++] = sma->s[i];
		}
	}
	xfa[j] = '\0';
	return (xfa);
}

double	select_dir(char	p)
{
	if (p == 'N')
		return (-(M_PI / 2));
	if (p == 'S')
		return (M_PI / 2);
	if (p == 'E')
		return (0);
	if (p == 'W')
		return (M_PI);
	return (0);
}

void	get_playerp(t_cub *cub)
{
	t_smap	*sma;
	int		y;
	int		x;

	sma = cub->sma;
	y = 0;
	while (sma)
	{
		x = -1;
		while (sma->s[++x])
		{
			if (ft_isplayer(sma->s[x]))
			{
				cub->px = (x * XFA) + (XFA / 2);
				cub->py = (y * XFA) + (XFA / 2);
				cub->pan = select_dir(sma->s[x]);
				cub->pdx = cos(cub->pan) * 5;
				cub->pdy = sin(cub->pan) * 5;
				cub->fov = M_PI / 3.0;
				return ;
			}
		}
		y++;
		sma = sma->nxt;
	}
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
	get_playerp(cub);
}