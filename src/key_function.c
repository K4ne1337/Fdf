/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:31:12 by abelkhay          #+#    #+#             */
/*   Updated: 2019/05/21 16:32:23 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_function.h"

int			key_function_part_1(int keycode, t_fdf *ptr)
{
	if (keycode == 35)
	{
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		if (ptr->current_proj == ISOMETRIC_PROJECTION)
		{
			ft_switch_para(ptr);
			ptr->current_proj = PARALLEL_PROJECTION;
		}
		else if (ptr->current_proj == PARALLEL_PROJECTION)
		{
			ft_switch_iso(ptr);
			ptr->current_proj = ISOMETRIC_PROJECTION;
		}
		ft_print_map(ptr);
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
		switch_proj(ptr);
		ft_print_map(ptr);
	}
	if (keycode == 78)
	{
		ptr->high -= 5;
		set_high(ptr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		switch_proj(ptr);
		ft_print_map(ptr);
	}
	if (keycode == 53)
	{
		free(ptr);
		exit(0);
	}
	return (0);
}

int			mouse_function(int keycode, t_fdf *ptr)
{
	if (keycode == 121)
	{
		ptr->size -= 1;
		set_size(ptr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		switch_proj(ptr);
		ft_print_map(ptr);
	}
	if (keycode == 116)
	{
		ptr->size += 1;
		set_size(ptr);
		mlx_clear_window(ptr->mlx_ptr, ptr->win_ptr);
		switch_proj(ptr);
		ft_print_map(ptr);
	}
	return (0);
}

int			key_function(int keycode, t_fdf *ptr)
{
	key_function_part_1(keycode, ptr);
	key_function_part_2(keycode, ptr);
	mouse_function(keycode, ptr);
	set_color(keycode, ptr);
	set_offset_x(keycode, ptr);
	set_offset_y(keycode, ptr);
	return (0);
}
