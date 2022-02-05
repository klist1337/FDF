/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:51:25 by eassofi           #+#    #+#             */
/*   Updated: 2022/02/02 20:16:52 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	set_default(t_fdf *data)
{
	data->zoom = 20;
	data->z_zoom = 1;
	data->is_isometric = 1;
	data->v_angle = 0.8;
	data->win_x = 2000;
	data->win_y = 2000;
	data->shift_x = data->win_x / 3;
	data->shift_y = data->win_y / 3;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y,
			"FDF");
}

int	main(int ac, char **av)
{
	t_fdf	**matrix;

	if (ac == 2)
	{
		matrix = read_file(av[1]);
		set_default (&matrix[0][0]);
		draw(matrix);
		mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
		mlx_loop(matrix[0][0].mlx_ptr);
	}
	else
		ft_putstr("Syntax Wrong! Usage : [./fdf] [map.fdf]", 0);
	return (0);
}
