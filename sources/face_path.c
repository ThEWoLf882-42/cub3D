/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   face_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:04:15 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 14:39:42 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	select_i(char *lin)
{
	if (ft_strstr(lin, "NO"))
		return (0);
	if (ft_strstr(lin, "SO"))
		return (1);
	if (ft_strstr(lin, "WE"))
		return (2);
	if (ft_strstr(lin, "EA"))
		return (3);
	return (0);
}

void	face_path(t_cub *cub, char *lin)
{
	char	**face[4];
	char	*fa;
	int		i;

	face[0] = &cub->pts->no;
	face[1] = &cub->pts->so;
	face[2] = &cub->pts->we;
	face[3] = &cub->pts->ea;
	i = select_i(lin);
	while (*lin == ' ' || *lin == '\t')
		lin++;
	lin = lin + 2;
	while (*lin == ' ' || *lin == '\t')
		lin++;
	fa = ft_strdup(ft_clean(lin));
	if (*face[i])
		get_out_s(cub, "Faces Can be set one time\n");
	*face[i] = ft_strdup(fa);
	free(fa);
}
