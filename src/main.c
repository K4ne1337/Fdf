/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarcel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 18:42:11 by amarcel           #+#    #+#             */
/*   Updated: 2019/05/17 18:42:15 by amarcel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		ft_putendl("Usage : ./fdf File");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl("Bad usage or file does not exist");
		return (-1);
	}
	else
		ft_fdf(argv[1]);
	return (0);
}
