#ifndef FT_INIT_H
#define FT_INIT_H

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "params.h"
#include "fill_tab.h"
#include "read_file.h"

void	ft_init_window(t_fdf *ptr);
void	draw_line(t_fdf *ptr, t_point a, t_point b);
void	draw_lines(t_fdf *ptr, int i, int j);
int		mouse_function(int keycode, void *param, t_fdf *ptr);
int 	key_function(int keycode, t_fdf *ptr);
t_point **ft_switch_iso(t_fdf *ptr);
void	testprint(t_fdf *ptr);

#endif