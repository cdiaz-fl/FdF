/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:42:08 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/07 19:35:38 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include <math.h>

#include <stdio.h>

void	ft_decide(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	map->color = 0x00FFFFFF;
	if (a->z || b->z)
		map->color = 0x0000FF00;
	if (map->dy > map->dx)	
	{
		if (a->y > b->y)
		{
			ft_bresenham_high(map, img, b, a);
		}
		else
			ft_bresenham_high(map, img, a, b);
	}
	else if (map->dy == map->dx)	
	{
		if (a->x > b->x)
			ft_bresenham_equal(map, img, b, a);
		else
			ft_bresenham_equal(map, img, a, b);

	}
	else
	{
		if (a->x > b->x)
			ft_bresenham_low(map, img, b, a);
		else
			ft_bresenham_low(map, img, a, b);
	}
}

void	ft_x_dots(t_map *map, t_data *img, int x, int y)
{
	t_dot	a;
	t_dot	b;
	int	aux;

	a.x = x + map->blank;
	a.y = y;
	a.z = map->f_map[map->i][map->j + 1];
	b.x = x;
	b.y = y;
	b.z = map->f_map[map->i][map->j];
	aux = (a.x - a.y) * cos(0.8);
	a.y = (a.x + a.y) * sin(0.8) - a.z;
	a.x = aux;
	aux = (b.x - b.y) * cos(0.8);
	b.y = (b.x + b.y) * sin(0.8) - b.z;
	b.x = aux;
	map->dx = a.x - b.x;
	map->dy = a.y - b.y;
	map->plus = 1;
	if (map->dx < 0)
	{
		map->plus = -1;
		map->dx *= -1;
	}
	if (map->dy < 0)
	{
		map->dy *= -1;
		map->plus = -1;
	}
//	printf("x = %d      x1 = %d      y = %d      y1 = %d      z = %d \n", a.x, b.x, a.y, b.y, a.z);
//	printf("dX = %d      dY = %d       slope = %.4f\n\t----------\n", map->dx, map->dy, (float)map->dy/(float)map->dx);
	ft_decide(map, img, &a, &b);
}


void	ft_y_dots(t_map *map, t_data *img, int x, int y)
{
	t_dot	a;
	t_dot	b;
	int	aux;

	a.x = x;
	a.y = y;
	a.z = map->f_map[map->i][map->j];
	b.x = x;
	b.y = y - map->blank;
	b.z = map->f_map[map->i - 1][map->j];
	aux = (a.x - a.y) * cos(0.8);
	a.y = (a.x + a.y) * sin(0.8) - a.z;
	a.x = aux;
	aux = (b.x - b.y) * cos(0.8);
	b.y = (b.x + b.y) * sin(0.8) - b.z;
	b.x = aux;
	map->dx = a.x - b.x;
	map->dy = a.y - b.y;
	map->plus = 1;
	if (map->dx < 0)
	{
		map->plus = -1;
		map->dx *= -1;
	}
	if (map->dy < 0)
	{
		map->dy *= -1;
		map->plus = -1;
	}
	ft_decide(map, img, &a, &b);
}

void	ft_bresenham_high(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;


	x = a->x;
	y = a->y;
	map->p = (2 * map->dx) - map->dy;
	while (y <= b->y)
	{
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, map->color);
		y++;
		if (map->p <= 0)
			map->p = map->p + (2 * map->dx);
		else
		{
			x += map->plus;
			map->p = map->p + (2 * (map->dx - map->dy));
		}
	}
}







void	ft_bresenham_low(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;

	x = a->x;
	y = a->y;
	map->p = (2 * map->dy) - map->dx;
	while (x <= b->x)
	{
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, map->color);
		x++;
		if (map->p <= 0)
			map->p = map->p + (2 * map->dy);
		else
		{
			y += map->plus;
			map->p = map->p + (2 * (map->dy - map->dx));
		}
	}
}




















void	ft_bresenham_equal(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;

	x = a->x;
	y = a->y;
	while (x <= b->x)
	{
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, map->color);
		y += map->plus;
		x++;
	}
}
