/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:51:59 by agimi             #+#    #+#             */
/*   Updated: 2023/07/29 18:22:22 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_map(t_cub *cub, char *fd)
{
	size_t	i;

	i = ft_strlen(fd) - 1;
	if ((fd[i - 3] != '.' || fd[i - 2] != 'c'
			|| fd[i - 1] != 'u' || fd[i] != 'b'))
		get_out_s(cub, "Hey You\nWhere is the cub\n");
	cub->fd = open(fd, O_RDONLY);
	if (cub->fd == -1)
		get_out_s(cub, "open failed\n");
}

void	read_map(t_cub *cub)
{
	char	*lin;

	lin = get_next_line(cub->fd);
	if (!lin)
		get_out_s(cub, "Empty file\n");
	while (1)
	{
		if (ft_strstr(lin, "NO") || ft_strstr(lin, "SO")
			|| ft_strstr(lin, "WE") || ft_strstr(lin, "EA"))
			face_path(cub, lin);
		if (ft_strstr(lin, "F") || ft_strstr(lin, "C"))
			color_set(cub, lin);
		free(lin);
		lin = get_next_line(cub->fd);
		if (!lin)
			break ;
	}
		printf("no[%s]\nso[%s]\nwe[%s]\nea[%s]\n", cub->pts->no, cub->pts->so, cub->pts->we, cub->pts->ea);
		printf("f[%x]\nc[%x]\n", cub->col->flo, cub->col->cei);
}
