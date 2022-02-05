/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:17:04 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 18:38:48 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	handle_key(int key)
{
	return (key == 123 || key == 124 || key == 125 || key == 126
		|| key == 69 || key == 24 || key == 78 || key == 27 || key == 22
		|| key == 26 || key == 88 || key == 89 || key == 49 || key == 0
		|| key == 2);
}

void	is_isometric(t_fdf **matrix)
{
	if (matrix[0][0].is_isometric)
		matrix[0][0].is_isometric = 0;
	else
		matrix[0][0].is_isometric = 1;
}

void	do_key(int key, t_fdf **matrix)
{
	if (key == 126)
		matrix[0][0].shift_y -= 150;
	if (key == 125)
		matrix[0][0].shift_y += 150;
	if (key == 123)
		matrix[0][0].shift_x -= 150;
	if (key == 124)
		matrix[0][0].shift_x += 150;
	if (key == 69 || key == 24)
		matrix[0][0].zoom += 3;
	if (key == 78 || key == 27)
		matrix[0][0].zoom -= 3;
	if (key == 0)
		matrix[0][0].z_zoom -= 1;
	if (key == 2)
		matrix[0][0].z_zoom += 1;
	if (key == 22 || key == 88)
		matrix[0][0].v_angle += 0.05;
	if (key == 26 || key == 89)
		matrix[0][0].v_angle -= 0.05;
	if (key == 49)
		is_isometric(matrix);
}

int	deal_key(int key, t_fdf **matrix)
{
	if (handle_key(key))
	{
		mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		do_key(key, matrix);
		menu(matrix[0][0]);
		draw(matrix);
	}
	if (key == 6 || key == 7 || key == 43 || key == 47 || key == 3)
		new_window(key, matrix);
	if (key == 53)
	{
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
