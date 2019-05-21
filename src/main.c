/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/21 19:00:50 by abelkhay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf File");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Bad usage or file does not exist");
		return (-1);
	}
	else
		ft_fdf(argv[1]);
	close(fd);
	return (0);
}
