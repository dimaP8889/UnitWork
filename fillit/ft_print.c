#include "header.h"

void	ft_print(char **mass)
{
	int line;
	int col;

	col = 0;
	line = 0;
	while (mass[col][line] != ',')
	{
		while (mass[col][line] != ',')
		{
			ft_putchar(mass[col][line]);
			line++;
		}
		ft_putchar('\n');
		line = 0;
		col++;
	}
}
