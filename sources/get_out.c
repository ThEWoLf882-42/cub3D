/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_out.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbelahse <fbelahse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 16:03:53 by agimi             #+#    #+#             */
/*   Updated: 2023/08/23 11:23:01 by fbelahse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_out_s(t_cub *cub, char *s)
{
	(void)cub;
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	free_all(cub);
	pause ();
	exit(1);
}
