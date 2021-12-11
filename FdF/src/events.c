/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 17:32:42 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/11 18:57:11 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../fdf.h"
#include	"../minilibx/mlx.h"
#include <stdlib.h>

void	shift_keys(int key, t_map *map)
{

	if (key == 123)
		map->x_shift -=50;
	if (key == 124)
		map->x_shift +=50;
	if (key == 126)
		map->y_shift -=50;
	if (key == 125)
		map->y_shift +=50;


}

int	manage_events(int key, t_map *map)
{
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->mlx_win);
		exit(0);
	}
	shift_keys(key, map);

	mlx_clear_window(map->mlx, map->mlx_win);
	mlx_destroy_image(map->mlx, map->img.img);
	map->img.img = mlx_new_image(map->mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp, &map->img.line_len, &map->img.endian);

	map->f_map = ft_allocate(map);
	map->color_map = ft_allocate(map);
	ft_create_map(map);
	ft_create_grid(map, 150, 150, &map->img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);	
	ft_freemap(map);
	return (0);	
}
