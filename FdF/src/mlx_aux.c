/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:19:50 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/06 12:43:40 by cdiaz-fl         ###   ########.fr       */
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

	printf("antes:\nx = %d \ny = %d \n\n", x, y);
	//ft_center_map(map, &x, &y);
	printf("después:\nx = %d \ny = %d \n\n", x, y);
	x += 500;
	y -= 700;
	ref = x;
	map->i = 0;
	//ft_print_map(map);
	while (map->i < map->height - 1)
	{
		map->j = 0;
		while (map->j < map->width - 1)
		{
			x += map->blank;
			ft_x_dots(map, img, x, y);
			//if (map->i > 0)
			//	ft_y_dots(map, img, x, y);
			map->j++;
		}
		x = ref;
		map->i++;
		y += map->blank;
	}
	(void)img;
}
