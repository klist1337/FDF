/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 00:59:39 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 14:07:56 by eassofi          ###   ########.fr       */
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
		data->color = 0xffffff;
	else
		data->color = 0x0a6522;
	if (b.z != a.z)
		data->color = 0x0a6522;
	else
		data->color = data->color;
}

void	bresenham(t_fdf a, t_fdf b, t_fdf *data)
{
	float	x_step;
	float	y_step;
	float	max;

	set_data(&a, &b, data);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	max = maximum(absolute(x_step), absolute(y_step));
	x_step /= max;
	y_step /= max;
	color(a, b, data);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, a.x, a.y, data->color);
		a.x += x_step;
		a.y += y_step;
		if (a.x > data->win_x || a.y > data->win_y || a.x < 0 || a.y < 0)
			break ;
	}
}

void	draw(t_fdf **matrix)
{
	int	x;
	int	y;

	menu(matrix[0][0]);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				bresenham(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				bresenham(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
