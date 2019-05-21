/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 16:54:51 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_file.h"

int		get_len(char *line)
{
	char	**sstr;
	t_fdf	tmp;

	sstr = ft_strsplit(line, ' ');
	tmp.nb_col = ft_sstrlen(sstr);
	freetab(sstr);
	return (tmp.nb_col);
}

int		read_file(char *filename, t_fdf *ptr)
{
	int	i;

	i = 0;
	ptr->fd = open(filename, O_RDONLY);
	while (get_next_line(ptr->fd, &ptr->line))
	{
		ptr->nb_line++;
		if (!ptr->line || (i == 1 && ptr->nb_col != get_len(ptr->line)))
		{
			ft_putendl("incorrect file");
			exit(0);
		}
		ptr->nb_col = get_len(ptr->line);
		free(ptr->line);
		i = 1;
	}
	if (!ptr->line)
	{
		ft_putendl("incorrect file");
		exit(0);
	}
	free(ptr->line);
	close(ptr->fd);
	return (0);
}

void	freetab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
