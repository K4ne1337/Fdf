/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 16:32:30 by abelkhay          #+#    #+#             */
/*   Updated: 2019/05/21 16:33:19 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef KEY_FUNCTION_H
#	define KEY_FUNCTION_H

#include "ft_init.h"

int		key_function(int keycode, t_fdf *ptr);
int		key_function_part_1(int keycode, t_fdf *ptr);
int		key_function_part_2(int keycode, t_fdf *ptr);
int		mouse_function(int keycode, t_fdf *ptr);

#	endif
