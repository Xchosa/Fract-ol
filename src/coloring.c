/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poverbec <poverbec@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 10:12:11 by poverbec          #+#    #+#             */
/*   Updated: 2025/02/24 15:39:09 by poverbec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"


// `R`     | Red Channel   | `0xFF000000`
// `G`     | Green Channel | `0x00FF0000`
// `B`     | Blue Channel  | `0x0000FF00`
// `A`     | Alpha Channel | `0x000000FF`


//32 bit integer 
//r = 255, g = 128, b = 64, a = 32.
// r << 24 results in 0xFF000000.
// g << 16 results in 0x00800000.
// b << 8 results in 0x00004000.
// a results in 0x00000020.
// get_rgba(255, 128, 64, 32) returns 0xFF804020.

int get_rgba(int r, int g, int b, int a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

int get_g(int rgba)
{
    // Move 2 bytes to the right and mask out the first byte.
    return ((rgba >> 16) & 0xFF);
}
void	default_color(t_fractol *fractol)
{
	uint32_t	i;
	uint32_t	j;
	double		t;

	i = 0;
	while(i <= fractol->iterations /2 )
	{
		t = (double)i / (fractol->iterations /2);
		fractol->color[i] = get_rgba(
			// Red: Cosine wave (no phase shift)
			(int)(127.5 * (1.0 + cos(2.0 * M_PI * t / 3.0))),
			 // Green: Cosine wave with 120° phase shift
			 // ensures values stay in 0, 255, da 127,5 * 1 + 
			(int)(127.5 * (1.0 + cos(2.0 * M_PI * t / 3.0 + 2.0 * M_PI / 3.0))),
			 // Blue: Cosine wave with 240° phase shift
			(int)(127.5 * (1.0 + cos(2.0 * M_PI * t / 3.0 + 4.0 * M_PI / 3.0))),
			// Alpha (transparency)
			200);
		i++;
	}
	j = i -1;
	while(i < fractol->iterations)
	{
		fractol->color[i]= fractol->color[j];
		i++;
		j++;
	}
}
