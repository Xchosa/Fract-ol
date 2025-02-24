/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_sets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:44:31 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/24 15:44:52 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"

#include <stdio.h>

void draw_mandelbrot(t_fractol *fractol)
{
	fractol->data->x = 0;
	while(((fractol->data->x)++) < (fractol->width_frac) + 1)
	{
		fractol->data->y = 0;
		while(((fractol->data->y)++) < (fractol->heigth_frac) + 1)
		{
			fractol->data->c_a = (fractol->data->x - WIDTH/2.0) * ( 4.0 / WIDTH) / fractol->zoom + fractol->offset_x;
			fractol->data->c_b = (fractol->data->y - HEIGHT/2.0) * (4.0 / WIDTH) / fractol->zoom + fractol->offset_y;
			// scales grind to -2. 2 
			fractol->data->a = 0;
			fractol->data->b = 0;
			fractol->data->n = 0;

			fractol->data->real_a = SQUARE(fractol->data->a) - SQUARE(fractol->data->b);
			fractol->data->imaginary_b = 2 * fractol->data->a * fractol->data->b;
			fractol->data->a = fractol->data->real_a + fractol->data->c_a; // Zˆ2 + c  (real)
			fractol->data->b =	fractol->data->imaginary_b + fractol->data->c_b; // Zˆ2 + c  (imaginary)
			if((SQUARE(fractol->data->a) + SQUARE(fractol->data->b)) > 4.0)
				break;// if not black 
			if(fractol->data->a == fractol->data->prev_a && fractol->data->b == fractol->data->prev_b)
				{
					fractol->data->n = fractol->iterations;
					break;
				}
			fractol->data->prev_a = fractol->data->a;
			fractol->data->prev_b = fractol->data->b;
			fractol->data->n++;
		}
	}
}