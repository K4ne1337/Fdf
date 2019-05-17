#include "read_file.h"

int	get_len(char *line)
{
	char	**sstr;
	t_fdf	tmp;

	sstr = ft_strsplit(line, ' ');
	tmp.nb_col = ft_sstrlen(sstr);
	free(sstr);
	return (tmp.nb_col); 
}

int	read_file(char *filename, t_fdf *ptr)
{
	ptr->fd = open(filename, O_RDONLY);

	while (get_next_line(ptr->fd, &ptr->line))
	{
		ptr->nb_line++;
		ptr->nb_col = get_len(ptr->line);
	}
	free(ptr->line);
	close(ptr->fd);
	return(0);
}