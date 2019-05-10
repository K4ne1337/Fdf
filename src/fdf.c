#include "fdf.h"

int	ft_fdf(char *filename)
{
	t_fdf	*ptr;

	if(!(ptr = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	read_file(filename,ptr);
	ptr->res = 800;
	ptr->moove = 600;
	ptr->up_down = 500;
	ptr->color = 0x00FFFFFF;
	ptr->size = ptr->res / (ptr->nb_col + ptr->nb_line);
	ptr->high = 2;
	fill_tab(filename, ptr);
	ft_init_window(ptr);
}