/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:19:50 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/08 19:46:00 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include <math.h>

#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int width, int height, int color)
{
	char	*dst;

	dst = data->addr + (height * data->line_len + width * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	ft_create_grid(t_map *map, int x, int y, t_data *img)
{
	int	ref;

	//ft_center_map(map, &x, &y);
	x += 500;
	y -= 700;
	ref = x;
	map->i = 0;
	while (map->i < map->height)
	{
		map->j = 0;
		while (map->j < map->width)
		{
			x += map->blank;
			if (map->j < map->width - 1)
				ft_x_dots(map, img, x, y);
			if (map->i > 0)
				ft_y_dots(map, img, x, y);
			map->j++;
		}
		//printf("width = %d, j = %d value = %d i = %d\n", map->width, map->j, map->f_map[map->i][map->j - 2], map->i);
		x = ref;
		map->i++;
		y += map->blank;
	}
}
