/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:51:27 by agimi             #+#    #+#             */
/*   Updated: 2023/08/24 11:54:13 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strchr(const char *s, int c)
{
	char	ac;
	char	*as;
	int		i;

	i = -1;
	as = (char *)s;
	ac = c;
	while (as[++i] != ac)
		if (as[i] == '\0')
			return (NULL);
	return ((char *)as + i);
}
