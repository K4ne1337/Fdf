#ifndef FILL_TAB_H
#define FILL_TAB_H

#include "../libft/libft.h"
#include "read_file.h"
#include "get_next_line.h"

t_point	**fill_tab(char *filename, t_fdf *ptr);
void	display_tab(t_point **tab, t_fdf *ptr);

#endif