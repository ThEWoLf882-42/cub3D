/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:25 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 10:50:04 by agimi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		init(&cub, av[1]);
		clear_smap(&cub.sma);
	}
	else
		ft_putstr_fd("Please Enter a .cub arg (only)\n", 2);
}
