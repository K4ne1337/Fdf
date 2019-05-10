#include "params.h"

void	set_proj(t_fdf *ptr)
{
	size_t	i;
	size_t 	j;

	j = 0;
	while (j <ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			i++;
		}
		j++;
	}
}

void	set_high(t_fdf *ptr)
{
	size_t i;
	size_t j;

	i = 0;
	while (i < ptr->nb_line)
	{
		j = 0;
		while (j < ptr->nb_col)
		{
			ptr->tab[i][j].z = ptr->tab[i][j].z0 * ptr->high;
			j++;
		}
		i++;
	}
}

void	set_color(int keycode, t_fdf *ptr)
{
	if (keycode == 114) // 15
	{
		ptr->color = 0x00FF0000;
		testprint(ptr);
	}
	if (keycode == 103) // 5
	{
		ptr->color = 0x0000FF00;
		testprint(ptr);
	}
	if (keycode == 98) // 11
	{
		ptr->color = 0x000000FF;
		testprint(ptr);
	}
	if (keycode == 119) // 13
	{
		ptr->color = 0x00FFFFFF;
		testprint(ptr);
	}
}

void	set_moove(int keycode, t_fdf *ptr)
{
	if (keycode == 65361) //123
	{
		ptr->moove -= 50;
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		testprint(ptr);
	}
	if (keycode == 65363) // 124
	{
		ptr->moove += 50;
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		testprint(ptr);
	}
}

void	set_up_down(int keycode, t_fdf *ptr)
{
	if (keycode == 65362) //126
	{
		ptr->up_down -= 50;
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		testprint(ptr);
	}
	if (keycode == 65364) // 125
	{
		ptr->up_down += 50;
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		testprint(ptr);
	}
}