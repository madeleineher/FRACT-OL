

#include "../includes/fractol.h"

void	error(int i)
{
	if (i == 1)
		ft_putendl("usage: ./fractol FRACTOL_NAME/S");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		error(1);

	return (0);
}
