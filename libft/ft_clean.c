/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:38:23 by agimi             #+#    #+#             */
/*   Updated: 2023/07/29 14:22:16 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*ft_clean(char *c)
{
	size_t	i;

	i = ft_strlen(c);
	while (c[--i] && c[i] == ' ')
		;
	c[++i] = '\0';
	return (c);
}