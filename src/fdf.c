/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/24 16:26:38 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	errors(int i)
{
	if (i == 0)
		ft_putendl("invalid values");
	else if (i == 1)
		ft_putendl("incorrect file");
	else if (i == 2)
		ft_putendl("Usage : ./fdf File");
	else if (i == 3)
		ft_putendl("Bad usage or file does not exist");
	exit(0);
}

int		ft_fdf(char *filename)
{
	t_fdf	*ptr;

	ptr = NULL;
	if (!(ptr = (t_fdf*)malloc(sizeof(t_fdf))))
		return (0);
	ptr->nb_line = 0;
	ptr->nb_col = 0;
	read_file(filename, ptr);
	ptr->res_width = 1280;
	ptr->res_height = 960;
	ptr->offset_x = 400;
	ptr->offset_y = 150;
	ptr->color = 0x00FFFFFF;
	ptr->current_proj = PARALLEL_PROJECTION;
	ptr->size = ptr->res_width / (ptr->nb_col + ptr->nb_line);
	ptr->high = 2;
	fill_tab(filename, ptr);
	if (!(ft_init_window(ptr)))
		return (-1);
	return (0);
}
