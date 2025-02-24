/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:49:35 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/24 15:45:09 by poverbec         ###   ########.fr       */
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

# ifndef WIDTH
# 	define WIDTH 1920
# endif

# ifndef HEIGHT
# 	define HEIGHT 1080
# endif

# define MAX_KONTRAST 200
# define SQUARE(x) ((x) * (x))
# define BPP sizeof(int32_t)
// Bits per pixel 
// 4 Bits // if endian - only 8 bit colors 
#define stderr 2

typedef struct s_data
{
	float	a;// real
	float 	b; // imaginary
	float	prev_a; // detect infitie loop
	float	prev_b;
	float	c_a; // complex numbers
	float	c_b;
	float	real_a; // a*a - b *b 
	float	imaginary_b; // 2 * a *b (i ˆ2 = -1 )
	int		n; // iteration;
	int		x;
	int		y; // x element of 0  - (above 0) until Width with width) 
	int		iterMax;
}		t_data;

typedef struct s_fractol
{
	mlx_image_t	*img;
	mlx_t		*mlx;
	t_data		*data;
	uint32_t	color[MAX_KONTRAST]; // always stay 32 Bits long
	uint32_t	iterations;
	
	float		zoom;
	float		width_frac;
	float		heigth_frac;
	float		offset_x;
	float		offset_y;
	float		start_point_x;
	float		start_point_y;
	int			fractol_set;		
	
}	t_fractol;



void	ft_error(void);
void	ft_escape_key(mlx_key_data_t keydata, void* param);
void	mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param);
void	init_fractol(t_fractol	*fractol, mlx_image_t *img, mlx_t *mlx);
void	default_color(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);

int		get_rgba(int r, int g, int b, int a);
int		get_g(int rgba);
void    leaks(void);

#endif