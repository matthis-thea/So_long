#include "../MLX42/include/MLX42/MLX42.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#define WIDTH 1920
#define HEIGHT 1080

int32_t	main(void)
{
	mlx_t	*mlx;
	mlx_image_t *image;
	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	image = mlx_new_image(mlx, 20, 20);
	if(!image)
		return(EXIT_FAILURE);
	memset(image->pixels, 245, image->width * image->height * sizeof(int32_t));
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_loop(mlx);
	
	return (EXIT_SUCCESS);
}

