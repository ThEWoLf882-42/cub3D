/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 14:25:05 by agimi             #+#    #+#             */
/*   Updated: 2023/07/31 12:41:17 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	select_i(t_cub *cub, char *lin)
{
	if (!ft_strncmp(lin, "F ", 2))
		return (0);
	if (!ft_strncmp(lin, "C ", 2))
		return (1);
	get_out_s(cub, "Nice Try\n");
	return (0);
}

void	color_check(t_cub *cub, int rgb[])
{
	if (rgb[0] < 0 || rgb[0] > 255)
		get_out_s(cub, "R,G,B colors range [0,255]\n");
	if (rgb[1] < 0 || rgb[1] > 255)
		get_out_s(cub, "R,G,B colors range [0,255]\n");
	if (rgb[2] < 0 || rgb[2] > 255)
		get_out_s(cub, "R,G,B colors range [0,255]\n");
}

void	color_set(t_cub *cub, char *lin)
{
	unsigned int	*co[2];
	int				rgb[3];
	int				i;

	co[0] = &(cub->col->flo);
	co[1] = &(cub->col->cei);
	while (*lin == ' ' || *lin == '\t')
		lin++;
	i = select_i(cub, lin);
	lin++;
	rgb[0] = ft_atoi(lin);
	while (*lin && *lin != ',')
		lin++;
	rgb[1] = ft_atoi(++lin);
	while (*lin && *lin != ',')
		lin++;
	rgb[2] = ft_atoi(++lin);
	while (*lin && *lin != ',')
		lin++;
	color_check(cub, rgb);
	if (*lin)
		get_out_s(cub, "Tomany ,\n");
	if (*co[i])
		get_out_s(cub, "Colors Can be set one time\n");
	*co[i] = get_rgba(rgb[0], rgb[1], rgb[2]);
}
