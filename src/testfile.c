#include "../inc/fractol.h"
#include "../mlx/include/MLX42/MLX42.h"

int	main(int ac, char**av)
{
	(void)ac;
	(void)av;

	
	t_fractol	z;
	t_fractol	c;
	float		tmp_real;

	// z = zi + c
	// z =zˆ2 + c
	
	z.real = 0;
	z.i = 0;
	
	c.real = 5;
	c.i = 2;
	
	int i = 0;
	// xˆ2 - y ˆ2 + 2 x yi
	while(i < 42 )
	{
		tmp_real= (z.real * z.real) - (z.i * z.i);
		c.i = 2 * z.i * c.real;
		z.real = tmp_real;
		z.i = z.i + c.i;
		i++;
		ft_printf("iterations n -> %f | real %f | imaginary %f \n", i, z.real, z.i);
	}
}
