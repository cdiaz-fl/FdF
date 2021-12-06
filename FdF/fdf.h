#ifndef FDF_H
# define FDF_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct	s_map {
	int	fd;
	int	height;
	int	width;
	int	blank;
	char	**tmp;
	int		**f_map;
	int	i;
	int	j;
	int	dx;
	int	dy;
	int	p;
}	t_map;

typedef struct	s_dot {
	int	x;
	int	y;
	int	z;
} t_dot;

int	main(int argc, char **argv);
void	ft_get_map_size(t_map *map, char *argv, int rows, int cols);
void	ft_create_map(t_map *map, char *argv);
void	ft_init_mlx(t_map *map);
void	ft_create_grid(t_map *map, int x, int y, t_data *img);
void	my_mlx_pixel_put(t_data *data, int width, int height, int color);
void	ft_x_dots(t_map *map, t_data *img, int x, int y);
void	ft_y_dots(t_map *map, t_data *img, int x, int y);
void	ft_bresenham_high(t_map *map, t_data *img, t_dot *a, t_dot *b);
void	ft_bresenham_equal(t_data *img, t_dot *a, t_dot *b);
void	ft_bresenham_low(t_map *map, t_data *img, t_dot *a, t_dot *b);



#endif
