/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:42:08 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/03 20:20:58 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include <math.h>

void	ft_x_dots(t_map *map, int x1, int y1, int z)
{
	int	x2;
	int	y2;
	int	z2;

	if (j < map->width - 1)
	{
		x2 = x1 + map->blank;
		y2 = y1;

		z2 = map->f_map[map->i][map->j + 1];
		x1 = (x1 - y1) * cos(0.8);
		y1 = (x1 + y1) * sin(0.8) - z;

		x2 = (x2 - y2) * cos(0.8);
		y2 = (x2 + y2) * sin(0.8) - z2;

	}
}

void	ft_y_dots(t_map *map, int x1, int y1, int z)
{
	int	x2;
	int	y2;
	int	z2;

	if (i > 0)
	{
		x2 = ref_x;
		y2 = ref_y - map->blank;

		z2 = map->f_map[map->i - 1][map->j]
		x2 = map->j;
		y2 = map->i ;
		x2 = (x2 - y2) * cos(0.8);
		y2 = (x2 + y2) * sin(0.8) - z2;

	}


}
