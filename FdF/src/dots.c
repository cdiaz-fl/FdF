/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dots.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 16:42:08 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/11 18:52:48 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

void	ft_decide(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	if (map->dy >= map->dx)	
	{
		if (a->y > b->y)
		{
			ft_bresenham_high(map, img, b, a);
		}
		else
		{
			ft_bresenham_high(map, img, a, b);
		}
	}
	else
	{
		if (a->x > b->x)
		{
			ft_bresenham_low(map, img, b, a);
		}
		else
		{
			if (a->y < b->y)
				map->plus = 1;
			ft_bresenham_low(map, img, a, b);
		}
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
	a.color = map->color_map[map->i][map->j + 1];
	b.x = x;
	b.y = y;
	b.z = map->f_map[map->i][map->j];
	b.color = map->color_map[map->i][map->j];
	aux = (a.x - a.y) * cos(M_PI / 6);
	a.y = (a.x + a.y) * sin(M_PI / 6) - (a.z);
	a.x = aux;
	aux = (b.x - b.y) * cos(M_PI / 6);
	b.y = (b.x + b.y) * sin(M_PI / 6) - (b.z);
	b.x = aux;
	a.x += map->x_shift;
	b.x += map->x_shift;
	a.y += map->y_shift;
	b.y += map->y_shift;
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
//	if (map->i == 2 && map->j == 1)
//		printf("x = %d      x1 = %d      y = %d      y1 = %d      z = %d \n", a.x, b.x, a.y, b.y, a.z);
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
	b.color = map->color_map[map->i][map->j];
	b.x = x;
	b.y = y - map->blank;
	b.z = map->f_map[map->i - 1][map->j];
	b.color = map->color_map[map->i - 1][map->j];
	aux = (a.x - a.y) * cos(M_PI / 6);
	a.y = (a.x + a.y) * sin(M_PI / 6) - (a.z);
	a.x = aux;
	aux = (b.x - b.y) * cos(M_PI / 6);
	b.y = (b.x + b.y) * sin(M_PI / 6) - (b.z);
	b.x = aux;
	a.x += map->x_shift;
	b.x += map->x_shift;
	a.y += map->y_shift;
	b.y += map->y_shift;
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
//	if (map->i == 2 && map->j == 1)
//		printf("x = %d      x1 = %d      y = %d      y1 = %d      z = %d \n", a.x, b.x, a.y, b.y, a.z);
	ft_decide(map, img, &a, &b);
}

void	ft_bresenham_high(t_map *map, t_data *img, t_dot *a, t_dot *b)
{
	int	x;
	int	y;


	x = a->x;
	y = a->y;
	map->dx = b->x - a->x;
	map->dy = b->y - a->y;
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
	map->p = (2 * map->dx) - map->dy;
	ft_change_color(map, a, b);
	while (y <= b->y)
	{

		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, a->color);
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
	ft_change_color(map, a, b);
	while (x <= b->x)
	{
		if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
			my_mlx_pixel_put(img, x,  y, a->color);
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

void	ft_change_color(t_map *map, t_dot *a, t_dot *b)
{
	if (ft_check_if_hex_color(map))
	{
		if (b->z != 0 || a->z != 0)
			a->color = 0x0000FF00;
	}
}

int	ft_check_if_hex_color(t_map *map)
{
	int	i;
	int j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->color_map[i][j] != 0x00FFFFFF)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
