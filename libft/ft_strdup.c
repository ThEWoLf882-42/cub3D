/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:22:27 by agimi             #+#    #+#             */
/*   Updated: 2023/07/29 11:23:22 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*ad;

	i = -1;
	while (s1[++i])
		;
	ad = (char *)malloc(sizeof(char) * (i + 1));
	if (!ad)
		return (NULL);
	i = -1;
	while (s1[++i])
		ad[i] = s1[i];
	ad[i] = '\0';
	return (ad);
}
