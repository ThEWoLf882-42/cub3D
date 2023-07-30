/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:23:37 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 10:01:02 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*kra(int fd, char *naah)
{
	char	*buff;
	int		ak;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	ak = 1;
	while (!ft_strchrg(naah, '\n') && ak != 0)
	{
		ak = read(fd, buff, BUFFER_SIZE);
		if (ak == -1)
		{
			free(buff);
			free(naah);
			naah = NULL;
			break ;
		}
		buff[ak] = '\0';
		naah = ft_strjoing(naah, buff);
	}
	free(buff);
	return (naah);
}

char	*get_next_line(int fd)
{
	char		*ster;
	static char	*naah[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	naah[fd] = kra(fd, naah[fd]);
	if (!naah[fd])
		return (NULL);
	ster = thisone(naah[fd]);
	naah[fd] = notthisone(naah[fd]);
	return (ster);
}
