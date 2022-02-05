/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassofi <eassofi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:35:02 by eassofi           #+#    #+#             */
/*   Updated: 2022/01/03 15:58:34 by eassofi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len_src;
	size_t	len;

	len_src = 0;
	len = dstsize - 1;
	while (src[len_src])
		len_src++;
	if (!dstsize)
		return (len_src);
	while (*src && len > 0)
	{
		*dst++ = *src++;
		len--;
	}
	*dst = '\0';
	return (len_src);
}
