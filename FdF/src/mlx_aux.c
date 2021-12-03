/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:19:50 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/03 20:21:00 by cdiaz-fl         ###   ########.fr       */
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
	ft_center_map(map, &x, &y);
	printf("después:\nx = %d \ny = %d \n\n", x, y);
	ref = x;
	map->i = 0;
	//ft_print_map(map);
	while (map->i < map->height - 1)
	{
		map->j = 0;
		while (map->j < map->width - 1)
		{
			x += map->blank;
			ft_iso(x, y, img, map->f_map[map->i][map->j]);
			//ft_x_dots(map, x, y, map->f_map[map->i][map->j])
			map->j++;
		}
		x = ref;
		map->i++;
		y += map->blank;
	}
	(void)img;
}

void	ft_center_map(t_map *map, int *x, int *y)
{
	int	new_x;
	int	new_y;
	int i;
	int j;
	int	iso_x;
	int	iso_y;

	new_x = 0;
	new_y = 0;
	i = 0;
	j = 0;
	while (j <= map->width)
	{
		new_x += map->blank;
		j++;
	}
	iso_x = (new_x - *y) * cos(0.8);
	while (i <= map->height)
	{
		new_y += map->blank;
		i++;
	}
	iso_y = (iso_x + new_y) * sin(0.8);


	printf("iso x = %d\n", new_x);
	*x += ((1620 - new_x) / 2);
	*y += ((780 - new_y) / 2);

	*x += (new_x - iso_x);
	*y += (iso_y - new_y);

	printf("result: %d\n", ((780 - new_y) / 2));


}

void	ft_iso(int x, int y, t_data *img, int z)
{
	x = (x - y) * cos(0.8);
	y = (x + y) * sin(0.8) - z;

	if (x <= 1920 && y <= 1080 && x > 0 && y > 0)
		my_mlx_pixel_put(img, x,  y, 0x00FF0000);
}
