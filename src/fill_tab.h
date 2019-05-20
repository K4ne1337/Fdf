/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/17 19:16:18 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FILL_TAB_H
#	define FILL_TAB_H

#include "../libft/libft.h"
#include "read_file.h"
#include "get_next_line.h"

void	fill_tab(char *filename, t_fdf *ptr);
void	display_tab(t_point **tab, t_fdf *ptr);

#	endif
