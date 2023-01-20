/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 12:03:45 by mthea             #+#    #+#             */
/*   Updated: 2023/01/20 16:45:05 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/verification_ber.h"

mlx_image_t *g_img;
t_manage	man;


void	hook(void *param)
{
	mlx_t	*mlx;
	static int		i = 0;
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5;	
	ft_printf("Coordonees de x : %d\n", man.p_x);
	ft_printf("Coordonees de y : %d\n", man.p_y);
	ft_printf("Coordonees de x : %d\n", g_img->instances[0].x);
	ft_printf("Coordonees de y : %d\n", g_img->instances[0].y);
}

int placement_asset(char *path, t_manage *man, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
	int				x;

	texture = mlx_load_png(path);
	if (!texture)
		return (0);
	image = mlx_texture_to_image(mlx, texture);
	if (!image)
		return (0);
	x = mlx_image_to_window(mlx, image, man->x * 64, man->y * 64);
	if (x < 0)
		exit(EXIT_FAILURE);
	return (1);
}

int placement_p(char *path, t_manage *man, mlx_t *mlx)
{
	mlx_texture_t	*texture;
	int				x;

	texture = mlx_load_png(path);
	if (!texture)
		return (0);
	g_img = mlx_texture_to_image(mlx, texture);
	if (!g_img)
		return (0);
	x = mlx_image_to_window(mlx, g_img, man->x * 64, man->y * 64);
	if (x < 0)
		exit(EXIT_FAILURE);
	return (1);
}


int	open_map(t_manage *m, mlx_t *mlx, t_image *i)
{
	while (m->map[m->y])
	{
		while (m->map[m->y][m->x])
		{
			if (m->map[m->y][m->x] == '1')
				i->un =placement_asset("./Window_management/Images/1.png", m, mlx);
			else
			{
				if (m->map[m->y][m->x] == '\n')
					break;
				i->all = placement_asset("./Window_management/Images/all.png", m, mlx);
			}
			if (m->map[m->y][m->x] == 'C')
				i->c = placement_asset("./Window_management/Images/c.png", m, mlx);
			if (m->map[m->y][m->x] == 'G')
				i->g = placement_asset("./Window_management/Images/g.png", m, mlx);
			if (m->map[m->y][m->x] == 'E')
				i->e = placement_asset("./Window_management/Images/e.png", m, mlx);
			(m->x)++;
		}
		(m->y)++;
		m->x = 0;
	}
	return (1);
}
int	open_map_2(t_manage *m, mlx_t *mlx, t_image *i)
{
	while (m->map[m->y])
	{
		while (m->map[m->y][m->x])
		{
			if (m->map[m->y][m->x] == 'P')
				i->p = placement_p("./Window_management/Images/p.png", m, mlx);
			(m->x)++;
		}
		(m->y)++;
		m->x = 0;
	}
	return (1);
}
int32_t main(int argc, char **argv)
{
	mlx_t *mlx;
	t_image img;
	(void) argc;
	
	man.map = NULL;
	man.map = ft_allocation_totale(argv[1]);
	if (!man.map)
		return (0);
	man.p_x = ft_position_p_columns(man.map) + 1;
	man.p_y = ft_position_p_line(man.map) + 1;
	mlx = mlx_init((ft_number_columns(man.map) - 1) * 64, (ft_number_lines(man.map)) * 64, "SO_LONG", true);
	if (!mlx)
		exit(EXIT_FAILURE);
	man.x = 0;
	man.y = 0;
	open_map(&man, mlx, &img);
	man.x = 0;
	man.y = 0;
	open_map_2(&man, mlx, &img);
	mlx_put_string(mlx,"compteur de mouvement :", 0, 0);
	mlx_loop_hook(mlx, &hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	free(man.map);
	return (0);
}

