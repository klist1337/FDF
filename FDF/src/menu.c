/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:08:30 by eassofi           #+#    #+#             */
/*   Updated: 2022/02/01 16:52:31 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	menu(t_fdf data)
{
	char	*menu;

	menu = "Press[up],[down],[left],[right] in the keybord: for move picture;" ;
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 10, 0x03fc35, menu);
	menu = "Press [+] for zoom++ and press [-] for zoom--;";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 50, 0x03fc35, menu);
	menu = "Press Space for 3d/2d mode";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 90, 0x03fc35, menu);
	menu = "Press [6] or [7]  for rotation .";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 130, 0x03fc35, menu);
	menu = "Press [A] or [D] for Z_zoom.";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 170, 0x03fc35, menu);
	menu = "Press [Z] or [X] to change windows height";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 210, 0x03fc35, menu);
	menu = "Press [<] or [>] to change windows width .";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 250, 0x0000ff, menu);
	menu = "Press [F] : full screen";
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 290, 0x0000ff, menu);
}
