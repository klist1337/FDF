/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:31:29 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 18:21:21 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	get_z_point(char *line, t_fdf **matrix_point, int y)
{
	char	**nums;
	int		x;

	x = 0;
	nums = ft_split(line, ' ');
	while (nums[x])
	{
		matrix_point[y][x].z = ft_atoi(nums[x]);
		matrix_point[y][x].x = x;
		matrix_point[y][x].y = y;
		matrix_point[y][x].is_last = 0;
		free(nums[x++]);
	}
	free(nums);
	free(line);
	matrix_point[y][--x].is_last = 1;
	return (x);
}

t_fdf	**allocate_memory(char *filename)
{
	t_fdf	**memory;
	int		x;
	int		y;
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY, 0);
	line = get_next_line(fd);
	x = count_word(line, ' ');
	free(line);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	memory = (t_fdf **)malloc(sizeof (t_fdf *) * (++y + 1));
	while (y > 0)
		memory[--y] = (t_fdf *)malloc(sizeof (t_fdf) * (x + 1));
	close(fd);
	return (memory);
}

t_fdf	**read_file(char *file_name)
{
	int		fd;
	int		y;
	char	*line;
	t_fdf	**matrix_point;

	fd = open(file_name, O_RDONLY, 0);
	if (fd <= 0)
	{
		perror("");
		exit(1);
	}
	matrix_point = allocate_memory(file_name);
	y = 0;
	line = get_next_line(fd);
	while (line)
	{
		get_z_point(line, matrix_point, y++);
		line = get_next_line(fd);
	}
	free(line);
	matrix_point[y] = NULL;
	close(fd);
	return (matrix_point);
}
