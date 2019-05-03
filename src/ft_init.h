#ifndef FT_INIT_H
#define FT_INIT_H

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "fill_tab.h"
#include "read_file.h"

void	ft_init_window(t_fdf *ptr);
t_point **ft_switch_iso(t_fdf *ptr);
void	testprint(t_fdf *ptr);

#endif