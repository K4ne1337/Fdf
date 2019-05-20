/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 00:30:24 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

t_point		**ft_switch_iso(t_fdf *ptr)
{
	int i;
	int j;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			ptr->tab[j][i].x2 = ((sqrt(2) / 2)\
			* (ptr->tab[j][i].x - ptr->tab[j][i].y));
			ptr->tab[j][i].y2 = (sqrt(2.0 / 3.0) * ptr->tab[j][i].z)\
			- ((ptr->tab[j][i].x + ptr->tab[j][i].y) / sqrt(6));
			i++;
		}
		j++;
	}
	return (ptr->tab);
}

int			key_function_part_1(int keycode, t_fdf *ptr)
{
	if (keycode == 1)
		ft_putendl("R-G-B-W : colors\narrows : moove\n+ : high\n- : low\n");
	if (keycode == 35)
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		if (ptr->current_proj == ISOMETRIC_PROJECTION)
		{
			set_proj(ptr);
			ptr->current_proj = PARALLEL_PROJECTION;
		}
		else if (ptr->current_proj == PARALLEL_PROJECTION)
		{
			ft_switch_iso(ptr);
			ptr->current_proj = ISOMETRIC_PROJECTION;
		}
		testprint(ptr);
	}
	return (0);
}

int			key_function_part_2(int keycode, t_fdf *ptr)
{
	if (keycode == 69)
	{
		ptr->high += 5;
		set_high(ptr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		ft_switch_iso(ptr);
		switch_proj(ptr);
		testprint(ptr);
	}
	if (keycode == 78)
	{
		ptr->high -= 5;
		set_high(ptr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		ft_switch_iso(ptr);
		switch_proj(ptr);
		testprint(ptr);
	}
	if (keycode == 53)
	{
		free(ptr);
		exit(0);
	}
	return (0);
}

int			key_function(int keycode, t_fdf *ptr)
{
	key_function_part_1(keycode, ptr);
	key_function_part_2(keycode, ptr);
	set_color(keycode, ptr);
	set_offset_x(keycode, ptr);
	set_offset_y(keycode, ptr);
	return (0);
}

void		ft_init_window(t_fdf *ptr)
{
	ptr->mlx_ptr = mlx_init();
	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->res_width\
	, ptr->res_height, "fdf");
	switch_proj(ptr);
	testprint(ptr);
	mlx_key_hook(ptr->win_ptr, key_function, ptr);
	mlx_loop(ptr->mlx_ptr);
}
