#ifndef FDF_H
# define FDF_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

int	main(void);
void	my_mlx_pixel_put(t_data *data, int width, int height, int color);


#endif
