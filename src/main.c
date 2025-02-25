/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:48:27 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/24 15:48:11 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"

#include <stdio.h>



// void my_hello_key(mlx_key_data_t keydata, void* param)
// {
// 	(void) param;
// 	if (keydata.key == MLX_KEY_J && keydata.action == MLX_PRESS)
// 		puts("hello");
// }

// void mlx_scroll_hook(mlx_t* mlx, mlx_scrollfunc func, void* param)
// {/
// }



// `R`     | Red Channel   | `0xFF000000`
// `G`     | Green Channel | `0x00FF0000`
// `B`     | Blue Channel  | `0x0000FF00`
// `A`     | Alpha Channel | `0x000000FF`

// julia fc, c= -0.8 + 0.156i

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_fractol 		fractol;

	// atexit(leaks);
	
	if((ac == 2)&& ft_strncmp(av[1],"mandelbrot", 10 ))
	{
		fractol.fractol_set = 1;
	}
	
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	
	init_fractol(&fractol, img, mlx);
	
	//mlx_put_pixel(img, 5, 10, 0xFF0000FF);// ein pixel for demo
	//mlx_put_pixel(img, 50, 50, get_g(128));
	
	
	// ft_memset(img->pixels, 255, img->width * img->height * BPP);
	//BPP 4 bytes for for channels BPP sizeof(int32_t)
	mlx_key_hook(mlx, &ft_escape_key, &fractol);  
	// loop hook gets calles once per loop
	
	//mlx_image_to_window(mlx, img, 300, 50); // draw image at (0.0)
	mlx_image_to_window(fractol.mlx, fractol.img, 0, 0);

	
	mlx_loop(mlx);// infitie loop // pases adress of hook functions 
	mlx_terminate(mlx);//freed every left over
	return (EXIT_SUCCESS);
}


void init_fractol(t_fractol	*fractol, mlx_image_t *img, mlx_t *mlx)
{
	fractol->img = img;
	fractol->mlx = mlx;
	fractol->zoom = 1;
	fractol->width_frac = WIDTH;
	fractol->heigth_frac = HEIGHT;
	fractol->iterations = 11;
	
	fractol->offset_x = 0;
	fractol->offset_y = 0;
	printf("init fractol");
	if (fractol->fractol_set == 1) // set default falue in main
		{
			fractol->offset_x = -1.40117; // Seahorse Valley
			fractol->offset_y = 0;
		}
	default_color(fractol);
	draw_mandelbrot(fractol);
}






// {
// 	mlx_put_pixel()
// 	every point mit der formular 
	
// }



// void mandelbrot_set()
// {
// 	float a = 0;
// 	float b = 0;
// 	float a_squared = 0;
// 	float b_squared = 0;
// 	int iteration = 0;
// 	int iterMax = 200;

// 	while (iteration < iterMax && a_squared + b_squared < 4 ) /// |Z|ˆ2 aˆ2 + bˆ2 < 2ˆ2
// 	{
// 		b = 2 * a *b + y; // img i of Z calc 
// 		a = a_squared - b_squared + x;
		
// 		a_squared = a * a;
// 		b_squared = b * b;
// 		iteration++;
// 		printf("a %f | b %f", a , b);
// 	}
	
// }