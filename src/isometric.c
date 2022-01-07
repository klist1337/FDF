/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:04:35 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 14:20:10 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	isometric(t_fdf *point, float angle)
{
	point->x = (point->x - point->y) * cos(angle);
	point->y = (point->x + point->y) * sin(angle) - point->z;
}
