#include	"minilibx/mlx.h"

int	main(void)
{
	void	*mlx;
	//void	*mlx_win;
	void	*img;

	mlx = mlx_init();
//	mlx_win = mlx_new_window(mlx, 500, 500, "Hola Paco!");
//	mlx_loop(mlx);
	img = mlx_new_image(mlx, 1920, 1080);
}
