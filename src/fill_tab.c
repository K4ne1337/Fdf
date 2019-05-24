/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/24 16:27:17 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_tab.h"

void	fill_tab(char *filename, t_fdf *ptr)
{
	int i;
	int j;

	i = -1;
	ptr->tab = (t_point **)malloc(sizeof(t_point *) * ptr->nb_line);
	ptr->fd = open(filename, O_RDONLY);
	while ((ptr->ret = get_next_line(ptr->fd, &ptr->line)) > 0)
	{
		ptr->sstr = ft_strsplit(ptr->line, ' ');
		ptr->tab[++i] = (t_point *)malloc(sizeof(t_point) * ptr->nb_col);
		j = -1;
		while (ptr->sstr[++j])
		{
			ptr->tab[i][j].x = j * ptr->size;
			ptr->tab[i][j].y = i * ptr->size;
			ptr->tab[i][j].z0 = ft_atoi(ptr->sstr[j]);
			if (ft_strlen(ptr->sstr[j]) >= 9)
				errors(0);
			ptr->tab[i][j].z = ft_atoi(ptr->sstr[j]) * ptr->high;
			free(ptr->sstr[j]);
		}
		free(ptr->line);
		free(ptr->sstr);
	}
	free(ptr->line);
}
