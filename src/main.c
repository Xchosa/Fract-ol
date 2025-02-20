/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:48:27 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/20 11:15:20 by poverbec         ###   ########.fr       */
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
int	main(int ac, char**av)
{
	(void)ac;
	(void)av;
	mlx_t		*mlx;
	mlx_image_t	*img;
	
	int i = 0;

	// z = zi + c
	// z =zˆ2 + c
	
	
	
	// if((ac == 2)&& ft_strncmp(av[1],"julia", 5 ))
	// 	{
	// 		init_fractol()
	// 		set_julia();
	// 	}
	// ac == 2 mandelbrot 
	
	mlx = mlx_init(WIDTH, HEIGHT, "fractol", false);
	if (!mlx)
		ft_error();
	img = mlx_new_image(mlx, 256, 256); // 256x256 image
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();
	
	
	// mlx_put_pixel(img, 250, 250, 0xFF0000FF);// ein pixel for demo
	mlx_put_pixel(img, 50, 50, get_g(128));
	ft_memset(img->pixels, 255, img->width * img->height * BPP);
	//BPP 4 bytes for for channels BPP sizeof(int32_t)
	mlx_image_to_window(mlx, img, 300, 50); // draw image at (0.0)
	while(i < 42)
	{
		img->instances[0].x += 5;
		img->instances[0].y -= 5;
		i++;
	// mlx_loop_hook(data, ft_hook, data);
	// loop hook gets calles once per loop
	mlx_key_hook(mlx, &ft_escape_key, NULL);
	}	
	// key hook interrupts
	mlx_loop(mlx);// infitie loop // pases adress of hook functions 
	mlx_terminate(mlx);//freed every left over
	return (EXIT_SUCCESS);
}


// void ft_error(char *str)
// {
// 	if (ft_strncmp("BAD_IMG", str, 8) == 0)
// 		ft_putchar_fd("Error, could not creat image", 29);
// }


void init_fractol(t_fractol	*fractol, mlx_image_t *img, mlx_t *mlx)
{
	fractol->zoom = 1;
	fractol->width_frac = WIDTH;
	fractol->heigth_frac = HEIGHT;
	fractol->img = img;
	fractol->mlx = mlx;
	
}
