/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:59:39 by eassofi           #+#    #+#             */
/*   Updated: 2022/02/02 19:31:02 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	maximum(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	absolute(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	color(t_fdf a, t_fdf b, t_fdf *data)
{
	if (b.z || a.z)
		data->color = 0xffff00;
	else
		data->color = 0x22427c;
	if (b.z != a.z)
		data->color = 0x0080ff;
	else
		data->color = data->color;
}

void	dda_method(t_fdf a, t_fdf b, t_fdf *data)
{
	float	dx;
	float	dy;
	float	step;

	set_data(&a, &b, data);
	dx = b.x - a.x;
	dy = b.y - a.y;
	step = maximum(absolute(dx), absolute(dy));
	dx /= step;
	dy /= step;
	color(a, b, data);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, data->color);
		a.x += dx;
		a.y += dy;
		if (a.x > data->win_x || a.y > data->win_y || a.x < 0 || a.y < 0)
			break ;
	}
}

void	draw(t_fdf **matrix)
{
	int	x;
	int	y;
	int	height;
	int	width;

	menu(matrix[0][0]);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				dda_method(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				dda_method(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
