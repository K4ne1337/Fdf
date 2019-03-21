/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelkhay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 18:34:28 by abelkhay          #+#    #+#             */
/*   Updated: 2019/03/19 15:39:33 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef GET_NEXT_LINE_H
#	define GET_NEXT_LINE_H

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define BUFF_SIZE 3

int	get_next_line(const int fd, char **line);

#	endif
