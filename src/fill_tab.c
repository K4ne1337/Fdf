/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 00:22:26 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_tab.h"

void	display_tab(t_point **tab, t_fdf *ptr)
{
	int j;
	int i;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			ft_putnbr(tab[j][i].z);
			if (tab[j][i].z < 10)
				ft_putstr("  ");
			else
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

void	fill_tab(char *filename, t_fdf *ptr)
{
	int		i;
	int		j;
	char	**sstr;

	i = 0;
	ptr->tab = (t_point **)malloc(sizeof(t_point *) * ptr->nb_line);
	ptr->fd = open(filename, O_RDONLY);
	while ((ptr->ret = get_next_line(ptr->fd, &ptr->line)) > 0)
	{
		sstr = ft_strsplit(ptr->line, ' ');
		ptr->tab[i] = (t_point *)malloc(sizeof(t_point) * ptr->nb_col);
		j = -1;
		while (sstr[++j])
		{
			ptr->tab[i][j].x = j * ptr->size;
			ptr->tab[i][j].y = i * ptr->size;
			ptr->tab[i][j].z0 = ft_atoi(sstr[j]);
			ptr->tab[i][j].z = ft_atoi(sstr[j]) * ptr->high;
			free(sstr[j]);
		}
		free(ptr->line);
		free(sstr);
		i++;
	}
	free(ptr->line);
}
