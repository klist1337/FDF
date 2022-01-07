/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:14:23 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/06 18:36:34 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

# define BUFFER_SIZE 100

char			*get_next_line(int fd);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
size_t			ft_strlen(const char *str);
char			**ft_split(const char *s, char c);
int				ft_putnbr_int(int n, int count);
int				ft_putchar(char c, int count);
int				ft_atoi(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
int				count_word(const char *s, char c);
typedef struct s_fdf
{
	float	x;
	float	y;
	float	z;
	float	v_angle;
	int		is_last;
	int		win_x;
	int		win_y;
	int		color;
	int		zoom;
	int		z_zoom;
	int		shift_x;
	int		shift_y;
	int		is_isometric;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;
t_fdf			**read_file(char *file_name);
void			bresenham(t_fdf a, t_fdf b, t_fdf *data);
int				ft_putstr(const char *s, int count);
void			isometric(t_fdf *point, float angle);
void			set_data(t_fdf *a, t_fdf *b, t_fdf *data);
void			draw(t_fdf **data);
void			menu(t_fdf data);
int				deal_key(int key, t_fdf **matrix);
void			new_window(int key, t_fdf **matrix);
#endif
