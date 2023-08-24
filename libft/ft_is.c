/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 17:49:11 by agimi             #+#    #+#             */
/*   Updated: 2023/08/24 11:48:10 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_isspace(size_t c)
{
	if ((c == ' ' || c == '\t' || c == '\v'
			|| c == '\n' || c == '\f' || c == '\r'))
		return (1);
	return (0);
}

int	ft_sisspace(char *c)
{
	int	i;

	if (!c)
		return (1);
	i = -1;
	while (c[++i] && c[i] == ' ')
		;
	if (!c[i])
		return (1);
	return (0);
}

int	ft_isplayer(size_t c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	is_ascii(char c)
{
	if (c == 47)
		return (0);
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	is_col(char *c)
{
	int	i;

	if (!c)
		return (1);
	i = -1;
	while (c[++i]
		&& ((c[i] >= '0' && c[i] <= '9') || c[i] == ',' || c[i] == ' '))
		;
	if (!c[i])
		return (1);
	return (0);
}
