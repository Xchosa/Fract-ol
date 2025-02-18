/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 09:48:27 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/18 13:40:19 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"



int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void ft_escape_key(mlx_key_data_t keydata, void* param)
{
	(void) param;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}

int main(int ac, char**av)
{
	(void)ac;
	(void)av;
	mlx_t *data;
	mlx_image_t *img;

	data = mlx_init(WIDTH, HEIGHT, "fractol", false);
	
	img = mlx_new_image(data, 256, 256);
	mlx_put_pixel(img, 250, 250, 0xFF0000FF);// ein pixel for demo
	mlx_image_to_window(data, img, 0, 0);
	
	// mlx_loop_hook(data, ft_hook, data);
	// loop hook gets calles once per loop
	mlx_key_hook(data, &ft_escape_key, NULL);
	// key hook interrupts
	mlx_loop(data);// infitie loop // pases adress of hook functions 
	mlx_terminate(data);
}
