/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:42:08 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/06 12:38:57 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include <math.h>

#include <stdio.h>

void	ft_decide(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	if (map->dy > map->dx)	
	{
		if (a->y > b->y)
			ft_bresenham_high(map, img, b, a);
		else
			ft_bresenham_high(map, img, a, b);
	}
	else if (map->dy == map->dx)	
		ft_bresenham_equal(img, a, b);
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
	if (map->dx < 0)
		map->dx *= -1;
	if (map->dy < 0)
		map->dy *= -1;
	printf("x = %d      x1 = %d      y = %d      y1 = %d      z = %d \n", a.x, b.x, a.y, b.y, a.z);
	printf("dX = %d      dY = %d       slope = %.4f\n\t----------\n", map->dx, map->dy, (float)map->dy/(float)map->dx);
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
	if (map->dx < 0)
		map->dx *= -1;
	if (map->dy < 0)
		map->dy *= -1;
	printf("x = %d      x1 = %d      y = %d      y1 = %d      z = %d \n", a.x, b.x, a.y, b.y, a.z);
	printf("dX = %d      dY = %d       slope = %.4f\n\t----------\n", map->dx, map->dy, (float)map->dy/(float)map->dx);
	if (map->dy > map->dx)	
		ft_bresenham_high(map, img, &a, &b);
	else if (map->dy == map->dx)	
		ft_bresenham_equal(img, &a, &b);
	else
		ft_bresenham_low(map, img, &a, &b);
}

void	ft_bresenham_high(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;


	x = a->x;
	y = a->y;
	map->p = (2 * map->dx) - map->dy;
	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
		my_mlx_pixel_put(img, x,  y, 0x0000FF00);

	while (y > b->y + 1)
	{
		//printf("x = %d      y = %d      p = %d \n", x, y, map->p);
		y--;
		if (map->p <= 0)
			map->p = map->p + (2 * map->dx);
		else
		{
			x++;
			map->p = map->p + (2 * (map->dx - map->dy));
		}
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, 0x0000FF00);
	}



	if (b->x >= 0 && b->x <= 1920 && b->y >= 0 && b->y <= 1080)
		my_mlx_pixel_put(img, b->x,  b->y, 0x0000FF00);
}







void	ft_bresenham_low(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;


	x = a->x;
	y = a->y;
	map->p = (2 * map->dy) - map->dx;
	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
		my_mlx_pixel_put(img, x,  y, 0x00FF0000);

	while (x < b->x + 1)
	{
		//printf("x = %d      y = %d      p = %d \n", x, y, map->p);
		x++;
		if (map->p <= 0)
			map->p = map->p + (2 * map->dy);
		else
		{
			y--;
			map->p = map->p + (2 * (map->dy - map->dx));
		}
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, 0x00FF0000);
	}



	if (b->x >= 0 && b->x <= 1920 && b->y >= 0 && b->y <= 1080)
		my_mlx_pixel_put(img, b->x,  b->y, 0x00FF0000);
}




















void	ft_bresenham_equal(t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;


	printf("epaaaaaaaaa\n\n\n");
	x = a->x;
	y = a->y;
	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
		my_mlx_pixel_put(img, x,  y, 0x00FFFFFF);

	while (x < b->x)
	{
		y--;
		x++;
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, 0x00FFFFFF);
	}
}
