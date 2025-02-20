/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:49:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/20 11:06:24 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include <limits.h>
# include <stdbool.h>
# include <limits.h>
# include <sys/wait.h>
# include <math.h>
# include <pthread.h>
#include "../mlx/include/MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080

#define BPP sizeof(int32_t)
#define stderr 2

typedef struct s_fractol
{
	float	width;
	float	real;
	float	i;

	
	float		zoom;
	float		width_frac;
	float		heigth_frac;
	mlx_image_t	*img;
	mlx_t		*mlx;
}	t_fractol;

void	ft_error(void);
void	ft_escape_key(mlx_key_data_t keydata, void* param);
void	mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);

int		get_rgba(int r, int g, int b, int a);
int		get_g(int rgba);

#endif