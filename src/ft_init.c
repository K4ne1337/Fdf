#include "ft_init.h"

void	testprint(t_fdf *ptr)
{
	int color;
	int i;
	int	j;

	//p[0].z = ptr->tab[j][i].z;
	//p[0].x2 = ptr->tab[j][i].x2;
	//p[0].y2 = ptr->tab[j][i].y2;
	j = 0;
	color = 0xeb3986;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			mlx_pixel_put(ptr->mlx_ptr, ptr-> win_ptr, ptr->tab[j][i].x2, ptr->tab[j][i].y2, color);
			i++;
		}
		j++;
	}
}

t_point **ft_switch_iso(t_fdf *ptr)
{
	int i;
	int j;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			ptr->tab[j][i].x2 = ((sqrt(2) / 2) * (ptr->tab[j][i].x - ptr->tab[j][i].y));
			ptr->tab[j][i].y2 = ((sqrt(2) / sqrt(3)) * ptr->tab[j][i].z) - ((ptr->tab[j][i].x + ptr->tab[j][i].y) / sqrt(6));
			i++;
		}
		j++;
	}
	return (ptr->tab);
}

void	ft_init_window(t_fdf *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->res, ptr->res, "fdf");
	ft_switch_iso(ptr);
	testprint(ptr);
	mlx_loop(ptr->mlx_ptr);
}