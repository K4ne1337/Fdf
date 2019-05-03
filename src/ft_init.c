#include "ft_init.h"

void	draw_line(t_fdf *env, t_point a, t_point b)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(b.x2 - a.x2);
	dy = abs(b.y2 - a.y2);
	s[0] = (a.x2 < b.x2 ? 1 : -1);
	s[1] = (a.y2 < b.y2 ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (a.x2 != b.x2 || a.y2 != b.y2)
	{
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, a.x2, a.y2, 0x8b0000);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			a.x2 += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			a.y2 += s[1];
		}
	}
}


void	draw_lines(t_fdf *env, int i, int j)
{
	t_point p[2];

	p[0].z = env->tab[i][j].z;
	p[0].x2 = 500 + env->tab[i][j].x2;
	p[0].y2 = 300 - env->tab[i][j].y2;
	if (i < env->nb_line - 1)
	{
		p[1].x2 = 500 + env->tab[i + 1][j].x2;
		p[1].y2 = 300 - env->tab[i + 1][j].y2;
		draw_line(env, p[0], p[1]);
	}
	if (j < env->nb_col - 1)
	{
		p[1].x2 = 500 + env->tab[i][j + 1].x2;
		p[1].y2 = 300 - env->tab[i][j + 1].y2;
		draw_line(env, p[0], p[1]);
	}
}

void	testprint(t_fdf *ptr)
{
	int color;
	int i;
	int	j;
	int	dx;
	int dy;

	color = 0x8b0000;
	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			/*printf("x = %d, y = %d\n", ptr->tab[j][i].x2, ptr->tab[j][i].y2);
			mlx_pixel_put(ptr->mlx_ptr, ptr-> win_ptr, ptr->tab[j][i].x2+400, ptr->tab[j][i].y2+700, color);*/
				//printf("x0 = %d y0 = %d x1 = %d y1 = %d\n", ptr->tab[j][i].x2+400, ptr->tab[j][i].y2+700, ptr->tab[j][i+1].x2+400,  ptr->tab[j][i+1].y2+700); 
			draw_lines(ptr, j, i);

			i++;
		}

		if(j < ptr->nb_line - 1)
		{
			//printf("x0 = %d y0 = %d x1 = %d y1 = %d\n", ptr->tab[j][i].x2+400, ptr->tab[j][i].y2+700, ptr->tab[j+1][i].x2+400, ptr->tab[j+1][i].y2+700);
			//draw_line(ptr, ptr->tab[j][i].x2+400, ptr->tab[j][i].y2+700, ptr->tab[j+1][i].x2+400, ptr->tab[j+1][i].y2+700, color);
		}
		j++;
	}

	/*dx = abs(ptr->tab[i][j].x2 - )
	dy = abs(ptr->tab[i][j].y2 - )
	i = 0;
	color = 0x8b0000;
	while (i < ptr->nb_line)
	{
		j = 0;
		while (j < ptr->nb_col)
		{
			mlx_pixel_put(ptr->mlx_ptr, ptr-> win_ptr, ptr->tab[i][j].x2, ptr->tab[i][j].y2, color);
			j++;
		}
		i++;
	}
	//printf("nb col : %d/n", ptr->nb_col);
	//printf("nb line %d/n", ptr->nb_line);*/
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
			ptr->tab[j][i].y2 = (sqrt(2.0 / 3.0) * ptr->tab[j][i].z) - ((ptr->tab[j][i].x + ptr->tab[j][i].y) / sqrt(6));
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
	//display_tab(ptr->tab, ptr);
	testprint(ptr);
	mlx_loop(ptr->mlx_ptr);
}
