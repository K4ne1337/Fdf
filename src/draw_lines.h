/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lines.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 00:17:05 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef DRAW_LINES_H
#	define DRAW_LINES_H

#include "../libft/libft.h"
#include "ft_init.h"

void	draw_line(t_fdf *ptr, t_point a, t_point b);
void	draw_lines(t_fdf *ptr, int i, int j);
void	ft_print_map(t_fdf *ptr);
void	switch_proj(t_fdf *ptr);
void	print_menu(t_fdf *ptr);

#	endif
