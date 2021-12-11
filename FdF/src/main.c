/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 09:20:03 by cdiaz-fl          #+#    #+#             */
/*   Updated: 2021/12/11 18:57:15 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../minilibx/mlx.h"
#include	"../fdf.h"
#include	"../libft/libft.h"
#include <math.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>


void	ft_freetmp(t_map *map)
{
	int	i;

	i = 0;
	while (map->tmp[i])
	{
		free(map->tmp[i]);
		i++;
	}
	free(map->tmp);
}


void	ft_free_double_array(void **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_freemap(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->f_map[i]);
		free(map->color_map[i]);
		i++;
	}
	free(map->f_map);
	free(map->color_map);
}

void	p_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
			printf("p_map  \n");
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
	ft_initialize(&map, argv[1]);
	ft_get_map_size(&map, argv[1], 0, 0);
	map.f_map = ft_allocate(&map);
	map.color_map = ft_allocate(&map);
	ft_create_map(&map);
	ft_init_mlx(&map);
	ft_freemap(&map);
//	system("leaks fdf");
	mlx_loop(map.mlx);
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
	while (1)
	{
		result = get_next_line(map->fd);
		if (result == NULL)
			break ;
		map->tmp = ft_split(result, ' ');
		i = 0;
		while (map->tmp[i] && ft_is_nbr(map->tmp[i], -1, -1, NULL))
			i++;
		if (i > cols)
			cols = i;
		rows++;
		ft_freetmp(map);
	}
	map->height = rows;
	map->width = cols;
	close(map->fd);
}

int	**ft_allocate(t_map *map)
{
	int	i;
	int	**aux;

	aux = (int **)malloc(sizeof(int *) * (map->height + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while(i != map->height)
	{
		aux[i] = (int *)malloc(sizeof(int *) * map->width + 1);
		if (!aux)
			return (NULL);
		i++;
	}
	aux[i] = NULL;
	return (aux);

}

void	ft_create_map(t_map *map)
{
	int	i;
	int	j;
	int	k;
	char	**aux;



	map->fd = open(map->argv, O_RDONLY);
	if (map->fd == -1 && write(1, "\e[1;31mError: Invalid file\n", 27))
			exit (0);
	i = 0;
	while (map->tmp != NULL)
	{
		aux = ft_split(get_next_line(map->fd), ' ');
		if (aux == NULL)
			break ;
		map->tmp = aux;
		j = 0;
		k = 0;
		while (map->tmp[j])
		{
			if (ft_is_nbr(map->tmp[j], i, k, map))
			{
				if (!ft_strchr(map->tmp[j], ','))
					map->f_map[i][k] = ft_atoi(map->tmp[j]);	
				k++;
			}
			j++;
		}
		i++;
		ft_free_double_array((void **)aux);
	}
	close(map->fd);
}


void	ft_init_mlx(t_map *map)
{

	if (map->height > map->width)
		map->blank = 780 / map->height;
	else
		map->blank = 780 / map->width;
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, 1920, 1080, "fdf");
	map->img.img = mlx_new_image(map->mlx, 1920, 1080);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bpp, &map->img.line_len, &map->img.endian);
	ft_create_grid(map, 150, 150, &map->img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.img, 0, 0);	
	mlx_hook(map->mlx_win, 2, 1L<<0, manage_events, map);
}
