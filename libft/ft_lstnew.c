/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:20:12 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 09:21:17 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_smap	*ft_lstnew_m(char *s)
{
	t_smap	*new;

	new = malloc(sizeof(t_map));
	if (!new)
		return (NULL);
	new->s = s;
	new->nxt = NULL;
	return (new);
}
