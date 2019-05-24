/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/24 16:29:21 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_init.h"

void		ft_switch_para(t_fdf *ptr)
{
	int	i;
	int	j;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			ptr->tab[j][i].x2 = ptr->tab[j][i].x + 0.35 * ptr->tab[j][i].y;
			ptr->tab[j][i].y2 = ptr->tab[j][i].z - 0.35 * ptr->tab[j][i].y;
			i++;
		}
		j++;
	}
}

void		ft_switch_iso(t_fdf *ptr)
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
}

int			ft_init_window(t_fdf *ptr)
{
	if (!(ptr->mlx_ptr = mlx_init()))
		return (-1);
	if (!(ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, ptr->res_width\
	, ptr->res_height, "fdf")))
		return (-1);
	switch_proj(ptr);
	ft_print_map(ptr);
	mlx_key_hook(ptr->win_ptr, key_function, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
