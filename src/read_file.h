#ifndef READ_FILE_H
#define READ_FILE_H

#include <stdio.h>

#include "get_next_line.h"
#include "../libft/libft.h"

typedef struct s_point
{
    int x;
    int y;
    int z;
	int z0;
	int x2;
	int y2;
}              t_point;

#define ISOMETRIC_PROJECTION 0
#define PARALLEL_PROJECTION 1

typedef struct s_fdf
{
	t_point	**tab;
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

int		read_file(char *filename, t_fdf *ptr);
int		get_len(char *line);
void	fill_tab(char *filename, t_fdf *ptr);

#endif