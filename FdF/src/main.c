/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:20:03 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/08 19:56:46 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include	"../libft/libft.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

void	p_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
			//printf("%4d  \n", map->f_map[0][9]);
	while (i < map->height)
	{
		j = 0;

		while (j < map->width)
		{
			printf("%4d  ", map->f_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	main(int	argc,  char **argv)
{
	t_map	map;

	if (argc != 2 && write(1, "\e[1;31mError: Too few arguments\n", 32))
		exit (0);
	ft_get_map_size(&map, argv[1], 0, 0);
	ft_create_map(&map, argv[1]);
	//p_map(&map);
	printf("width: %4d    height: %4d \n", map.width, map.height);
	ft_init_mlx(&map);
}

void	ft_get_map_size(t_map *map, char *argv, int rows, int cols)
{
	char *result;
	int i;

	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1 && write(1, "\e[1;31mError: Invalid file\n", 27))
			exit (0);
	printf("fd = %d\n", map->fd);
	result = "1";
	while (result != NULL)
	{
		result = get_next_line(map->fd);
		if (result == NULL)
			break ;
		map->tmp = ft_split(result, ' ');
		i = 0;
		while (map->tmp[i] && ft_is_nbr(map->tmp[i]))
		{
			printf("eppiii");
			i++;
		}
		if (i > cols)
			cols = i;
		rows++;
	}
	map->height = rows;
	map->width = cols;
	close(map->fd);
}





void	ft_create_map(t_map *map, char *argv)
{
	int	i;
	int	j;
	int	k;

	map->f_map = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!map->f_map)
		return ;
	i = 0;
	while(i != map->height)
	{
		map->f_map[i] = (int *)malloc(sizeof(int *) * map->width + 1);
			if (!map->f_map)
				return ;
		i++;
	}
	map->fd = open(argv, O_RDONLY);
	if (map->fd == -1 && write(1, "\e[1;31mError: Invalid file\n", 27))
			exit (0);
	printf("fd = %d\n", map->fd);
	i = 0;
	while (map->tmp != NULL)
	{
		map->tmp = ft_split(get_next_line(map->fd), ' ');
		if (map->tmp == NULL)
			break ;
		j = 0;
		k = 0;
		while (map->tmp[j])
		{
			//printf("%s  ", map->tmp[j]);
			if (ft_is_nbr(map->tmp[j]))
			{
				map->f_map[i][k] = ft_atoi(map->tmp[j]);	
				printf("%4d ", map->f_map[i][k]);
				k++;
			}
			j++;
		}
		printf("\n");
		i++;
	}
	close(map->fd);
}




void	ft_init_mlx(t_map *map)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	if (map->height > map->width)
		map->blank = 780 / map->height;
	else
		map->blank = 780 / map->width;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "fdf");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_len, &img.endian);
	ft_create_grid(map, 150, 150, &img);
//	ft_isometric();
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
