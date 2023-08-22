/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:51:59 by agimi             #+#    #+#             */
/*   Updated: 2023/08/22 18:44:44 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	open_map(t_cub *cub, char *fd)
{
	size_t	i;

	i = ft_strlen(fd) - 1;
	if ((fd[i - 3] != '.' || fd[i - 2] != 'c'
			|| fd[i - 1] != 'u' || fd[i] != 'b' || !is_ascii(fd[i - 4])))
		get_out_s(cub, "Hey You\nWhere is the .cub\n");
	cub->fd = open(fd, O_RDWR);
	if (cub->fd == -1)
		get_out_s(cub, "open failed\n");
}

bool	ismap(char *lin)
{
	if (!ft_strstr(lin, "NO") && !ft_strstr(lin, "SO") && !ft_strstr(lin, "WE")
		&& !ft_strstr(lin, "EA") && !ft_strstr(lin, "F")
		&& !ft_strstr(lin, "C") && (ft_strstr(lin, "1") || ft_strstr(lin, "0")))
		return (true);
	return (false);
}

bool	allowed_c(char *li)
{
	int	i;

	i = -1;
	while (li[++i])
	{
		if (li[i] != ' ' && li[i] != '1' && li[i] != '0' && li[i] != 'N'
			&& li[i] != 'S' && li[i] != 'E' && li[i] != 'W' && li[i] != 'D')
			return (false);
	}
	return (true);
}

void	map_fill(t_cub *cub, char *lin)
{
	while (lin)
	{
		if (!allowed_c(lin))
		{
			free(lin);
			get_out_s(cub, "Not allowed char DETECTED\n");
		}
		ft_lstadd_back_m(&cub->sma, ft_lstnew_m(ft_strdup(ft_clean(lin))));
		free(lin);
		lin = get_next_line(cub->fd);
	}
}

void	read_map(t_cub *cub)
{
	char	*lin;

	lin = get_next_line(cub->fd);
	if (!lin)
		get_out_s(cub, "Empty file\n");
	while (lin)
	{
		if (ft_strstr(lin, "NO") || ft_strstr(lin, "SO")
			|| ft_strstr(lin, "WE") || ft_strstr(lin, "EA"))
			face_path(cub, lin);
		else if (ft_strstr(lin, "F") || ft_strstr(lin, "C"))
			color_set(cub, lin);
		else if (ismap(lin))
		{
			map_fill(cub, lin);
			break ;
		}
		else if (!ft_sisspace(lin))
		{
			free(lin);
			get_out_s(cub, "What is this line\n");
		}
		free(lin);
		lin = get_next_line(cub->fd);
	}
}
