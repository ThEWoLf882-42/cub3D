/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:39:48 by agimi             #+#    #+#             */
/*   Updated: 2023/08/22 19:42:07 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*an;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return ((char *)s1);
	an = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!an)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		an[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		an[i + j] = s2[j];
		j++;
	}
	an[i + j] = '\0';
	free((char *)s2);
	return (an);
}
