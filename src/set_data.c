/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:56:12 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 14:34:50 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	zoom(t_fdf *a, t_fdf *b, t_fdf *data)
{
	a->x *= data->zoom;
	a->y *= data->zoom;
	b->x *= data->zoom;
	b->y *= data->zoom;
	a->z *= data->z_zoom;
	b->z *= data->z_zoom;
}

void	shift(t_fdf *a, t_fdf *b, t_fdf *data)
{
	a->x += data->shift_x;
	a->y += data->shift_y;
	b->x += data->shift_x;
	b->y += data->shift_y;
}

void	set_data(t_fdf *a, t_fdf *b, t_fdf *data)
{
	zoom(a, b, data);
	if (data->is_isometric)
	{
		isometric(a, data->v_angle);
		isometric(b, data->v_angle);
	}
	shift(a, b, data);
}
