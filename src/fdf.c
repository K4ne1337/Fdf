#include "fdf.h"

int	ft_fdf(char *filename)
{
	t_fdf	*ptr;

	if(!(ptr = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	read_file(filename,ptr);
	ptr->res_width = 800;
	ptr->res_height = 600;
	ptr->offset_x = 200;
	ptr->offset_y = 150;
	ptr->color = 0x00FFFFFF;
	ptr->current_proj = PARALLEL_PROJECTION;
	ptr->size = ptr->res_width / (ptr->nb_col + ptr->nb_line);
	ptr->high = 2;
	fill_tab(filename, ptr);
	ft_init_window(ptr);
}