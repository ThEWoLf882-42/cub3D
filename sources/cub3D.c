/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agimi <agimi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:00:25 by agimi             #+#    #+#             */
/*   Updated: 2023/07/30 20:13:22 by agimi            ###   ########.fr       */
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
		free(cub.pts->no);
		free(cub.pts->so);
		free(cub.pts->we);
		free(cub.pts->ea);
	}
	else
		ft_putstr_fd("Please Enter a .cub arg (only)\n", 2);
}
