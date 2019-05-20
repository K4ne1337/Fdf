/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/17 19:17:43 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_INIT_H
#	define FT_INIT_H

#include <mlx.h>
#include <math.h>
#include "fdf.h"
#include "params.h"
#include "fill_tab.h"
#include "read_file.h"
#include "draw_lines.h"

void	ft_init_window(t_fdf *ptr);
int		key_function(int keycode, t_fdf *ptr);
int		key_function_part_1(int keycode, t_fdf *ptr);
int		key_function_part_2(int keycode, t_fdf *ptr);
t_point	**ft_switch_iso(t_fdf *ptr);

#	endif
