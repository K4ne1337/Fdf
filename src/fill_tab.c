#include "fill_tab.h"

void	display_tab(t_point **tab, t_fdf *ptr)
{
	int j;
	int i;

	j = 0;
	while (j < ptr->nb_line)
	{
		i = 0;
		while (i < ptr->nb_col)
		{
			ft_putnbr(tab[j][i].z);
			if (tab[j][i].z < 10)
				ft_putstr("  ");
			else
			{
				ft_putchar(' ');
			}
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}

t_point	**fill_tab(char *filename, t_fdf *ptr)
{
	int	i;
	int j;
	char	**sstr;

	i = 0;
	j = 0;
	ptr->tab = (t_point **)malloc(sizeof(t_point *) * ptr->nb_line);
	ptr->fd = open(filename, O_RDONLY);
	while ((ptr->ret = get_next_line(ptr->fd, &ptr->line)) > 0)
	{
		sstr = ft_strsplit(ptr->line, ' ');
		ptr->tab[i] = (t_point *)malloc(sizeof(t_point) * ptr->nb_col);
		j = 0;
		while (sstr[j])
		{
			ptr->tab[i][j].x = j * ptr->size;
			ptr->tab[i][j].y = i * ptr->size;
			ptr->tab[i][j].z0 = ft_atoi(sstr[j]);
			ptr->tab[i][j].z = ft_atoi(sstr[j]) * ptr->high;
			j++;
		}
		i++;
	}
	display_tab(ptr->tab, ptr);
}