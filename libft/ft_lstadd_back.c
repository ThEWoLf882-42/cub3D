/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:14:36 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 16:19:25 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_lstadd_back_m(t_smap **a, t_smap *new)
{
	if (!a || !new)
		return ;
	if ((*a))
	{
		new->prv = ft_lstlast_m((*a));
		ft_lstlast_m((*a))->nxt = new;
	}
	else
	{
		(*a) = new;
		(*a)->prv = NULL;
	}
}
