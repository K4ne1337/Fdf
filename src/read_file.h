/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 01:20:58 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef READ_FILE_H
#	define READ_FILE_H

#define ISOMETRIC_PROJECTION 0
#define PARALLEL_PROJECTION 1
#include "../libft/libft.h"

typedef struct	s_point
{
	int x;
	int y;
	int z;
	int z0;
	int x2;
	int y2;
}				t_point;

typedef struct	s_fdf
{
	t_point	**tab;
	char	**sstr;
	int		color;
	int		fd;
	int		ret;
	int		res_width;
	int		res_height;
	int		high;
	int		nb_line;
	int		nb_col;
	int		size;
	int		offset_x;
	int		offset_y;
	int		current_proj;
	char	*line;
	void	*win_ptr;
	void	*mlx_ptr;
}				t_fdf;

int				read_file(char *filename, t_fdf *ptr);
int				get_len(char *line);
void			fill_tab(char *filename, t_fdf *ptr);
void			freetab(char **str);
void			ft_error(t_fdf *ptr);

#	endif
