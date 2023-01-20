/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification_ber.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthea <mthea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:19:20 by mthea             #+#    #+#             */
/*   Updated: 2023/01/20 14:24:39 by mthea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERIFICATION_BER_H
# define VERIFICATION_BER_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE (10)
# endif
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include "../ft_printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_manage
{
			char	**map;
			char	**copie;
			int		x;
			int		y;
			int			p_x;
			int			p_y;
}				t_manage;

typedef struct	s_image
{
				int		e;
				int		p;
				int		c;
				int		un;
				int		all;
				int		g;
}				t_image;
char	*get_next_line(int fd);
char	*ft_reading_file(int fd, char *old_string);
char	*ft_strcopy_new(char *s);
char	*ft_clear_old(char *s);
int		ft_comp(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	**ft_free_malloc(char **tab, int pos);
char	*ft_strdup(char *source);
int		ft_allocation_lines(char *map);
char	**ft_allocation_colums(char **tab, char *map);
char	**ft_allocation_totale(char *map);
int		ft_verification_start_exit(char **string);
int		ft_verification_items(char **string);
int		ft_verification_wall(char **string);
int		ft_verification_rectangular(char **string);
int		ft_verification_totale(char **string);
void	ft_recursive_flood(char **tab, int pos_p_x, int pos_p_y, int *item);
void	ft_flood_fill(char **tab, t_point position_p, int *item);
int		ft_verification_flood_fill(char **map);
int		ft_number_columns(char **string);
int		ft_number_lines(char **string);
int		ft_position_p_columns(char **string);
int		ft_position_p_line(char **string);
int		ft_final_verification(char **map);
void	*ft_memset(void *str, int value, size_t n);
int		open_map(t_manage *man, mlx_t *mlx, t_image *img);
#endif