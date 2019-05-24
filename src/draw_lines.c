/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/24 16:25:33 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw_lines.h"

void	draw_line(t_fdf *ptr, t_point a, t_point b)
{
	int dx;
	int dy;
	int	s[2];
	int	err[2];

	dx = abs(b.x2 - a.x2);
	dy = abs(b.y2 - a.y2);
	s[0] = (a.x2 < b.x2 ? 1 : -1);
	s[1] = (a.y2 < b.y2 ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (a.x2 != b.x2 || a.y2 != b.y2)
	{
		mlx_pixel_put(ptr->mlx_ptr, ptr->win_ptr, a.x2, a.y2, ptr->color);
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

void	draw_lines(t_fdf *ptr, int i, int j)
{
	t_point	p[2];

	p[0].z = ptr->tab[i][j].z;
	p[0].x2 = ptr->offset_x + ptr->tab[i][j].x2;
	p[0].y2 = ptr->offset_y - ptr->tab[i][j].y2;
	if (i < ptr->nb_line - 1)
	{
		p[1].x2 = ptr->offset_x + ptr->tab[i + 1][j].x2;
		p[1].y2 = ptr->offset_y - ptr->tab[i + 1][j].y2;
		draw_line(ptr, p[0], p[1]);
	}
	if (j < ptr->nb_col - 1)
	{
		p[1].x2 = ptr->offset_x + ptr->tab[i][j + 1].x2;
		p[1].y2 = ptr->offset_y - ptr->tab[i][j + 1].y2;
		draw_line(ptr, p[0], p[1]);
	}
}

void	ft_print_map(t_fdf *ptr)
{
	int	i;
	int	j;

	j = 0;
	print_menu(ptr);
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			draw_lines(ptr, j, i);
			i++;
		}
		j++;
	}
}

void	switch_proj(t_fdf *ptr)
{
	if (ptr->current_proj == ISOMETRIC_PROJECTION)
		ft_switch_iso(ptr);
	else if (ptr->current_proj == PARALLEL_PROJECTION)
		ft_switch_para(ptr);
}

void	print_menu(t_fdf *ptr)
{
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 10\
			, 0x0000FF00, "R-G-B-W : colors");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 30\
			, 0x0000FF00, "P : switch projection");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 50\
			, 0x0000FF00, "arrows : moove");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 70\
			, 0x0000FF00, "page up : zoom");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 90\
			, 0x0000FF00, "page down : dezoom");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 110\
			, 0x0000FF00, "+ : high");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 130\
			, 0x0000FF00, "- : low");
	mlx_string_put(ptr->mlx_ptr, ptr->win_ptr, 10, 150\
			, 0x00FF0000, "ESC to quit");
}
