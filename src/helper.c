/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 09:47:03 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/20 16:19:05 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"

void	ft_escape_key(mlx_key_data_t keydata, void* param)
{
	// t_fractol *fractol;
	// param - das bild was jedes mal neu reingegeben wird 
	(void) param;
	// if(keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE)
	// 	fractol->img->width += 5;
	// if(keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE)
	// 	fractol->img->height + 5;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		exit(1);
	}
}

// while(&fractol.iterations < (float*)10)
// 	{
// 		img->instances[0].x += 5;
// 		img->instances[0].y -= 5;
// 		fractol.iterations++;
// 	}


void	ft_error(void)
{
	ft_printf("%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void    leaks(void)
{
    ft_printf("\n");
    system("leaks fractol");
}
// atexit(leaks);


