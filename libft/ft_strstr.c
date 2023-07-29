/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:51:04 by agimi             #+#    #+#             */
/*   Updated: 2023/07/29 10:56:43 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	if (!*needle)
		return ((char *)haystack);
	i = -1;
	while (haystack[++i])
	{
		j = -1;
		while (needle[++j] && needle[j] == haystack[i + j])
			if (!(needle[j + 1]))
				return ((char *)(haystack + i));
	}
	return (NULL);
}
