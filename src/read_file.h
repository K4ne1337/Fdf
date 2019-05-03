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

typedef struct s_fdf
{
	t_point	**tab;
	int		fd;
	int		ret;
	int		res;
	int		high;
	int		nb_line;
	int		nb_col;
	int		size;
	char	*line;
	void	*win_ptr;
	void	*mlx_ptr;
}				t_fdf;

int	read_file(char *filename, t_fdf *ptr);
int		get_len(char *line);
t_point	**fill_tab(char *filename, t_fdf *ptr);

#endif