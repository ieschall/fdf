#include "fdf.h"

int	mlx_prepare(t_mlx *mlx, int line, int color, int endian)
{
	if ((mlx->ptr = mlx_init()) == NULL)
		return (-1);
	if ((mlx->win = mlx_new_window(mlx->ptr, 1366, 768, "FdF")) == NULL)
	{
		free(mlx->ptr);
		return (-1);
	}
	if ((mlx->img_plot = mlx_new_image(mlx->ptr, 1366, 768)) == NULL)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		return (-1);
	}
	if ((mlx->plot = mlx_get_data_addr(
		mlx->img_plot, &color, &line, &endian)) == NULL)
	{
		mlx_destroy_image(mlx->ptr, mlx->win);
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		return (-1);
	}
	return (0);
}
