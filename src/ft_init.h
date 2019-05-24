/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/24 16:29:32 by abelkhay         ###   ########.fr       */
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
#include "key_function.h"

int		ft_init_window(t_fdf *ptr);
void	ft_switch_para(t_fdf *ptr);
void	ft_switch_iso(t_fdf *ptr);

#	endif
