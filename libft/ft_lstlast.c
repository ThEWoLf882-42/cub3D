/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:16:39 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 13:25:19 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

t_smap	*ft_lstlast_m(t_smap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nxt)
		lst = lst->nxt;
	return (lst);
}

t_smap	*ft_lstblast_m(t_smap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->nxt->nxt)
		lst = lst->nxt;
	return (lst);
}
