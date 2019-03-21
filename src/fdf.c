#include <mlx.h>
#include <stdio.h>
#include "get_next_line.h"
#include "../libft/libft.h"
#include "fdf.h"

int	char_number(char *str)
{
	int	i;
    int compteur;

	i = 0;
	compteur = 0;
    while (str[i] != '\n' && str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            while (str[i + 1] >= '0' && str[i + 1] <= '9')
                i++;
            compteur++;
 
        }
        i++;
    }
	return (compteur);
}

void	displaygrid(char **grid, int nbline, int col)
{
	int x;
	int	y;

	x = 0;
	y = 0;
	while (y < nbline)
	{
		x = 0;
		while (x < col)
		{
			ft_putchar(grid[x][y]);
			++x;
		}
		ft_putchar('\n');
		++y;
	}
}

char    **creategrid(int nbline, int col)
{
    int i;
    int j;
    char **ret;

    i = 0;
    ret = (char **)malloc(sizeof(char *) * col);
    while (i < col)
    {
        ret[i] = (char *)malloc(sizeof(char) * nbline);
        j = 0;
        while (j < col)
        {
            ret[i][j] = '.';
            j++;
        }
        i++;
    }
    return (ret);
}

void    stockfile(char *filename, char *line)
{
    int i;
    int fd;
    int nbline;
    int col;
    char **str;

    str = NULL;
    i = 0;
    nbline = 0;
    col = 0;
    fd = open(filename, O_RDONLY);
    while (get_next_line(fd, &line) == 1)
    {
        nbline++;
        col = char_number(line);
        //ft_putendl(line);
        //free(line);
    }
    str = creategrid(nbline, col);
    displaygrid(str, nbline, col);
}

int main(int argc, char **argv)
{
    //void    *win_ptr;
    //void    *mlx_ptr;
    char    *line;
    
   // x = 300;
   // y = 800;
   // color = 0xeb3986;
    //mlx_ptr = mlx_init();
    //win_ptr = mlx_new_window(mlx_ptr, 900 , 1200, "Salut");
    //mlx_pixel_put(mlx_ptr, win_ptr, 100, 100, color);
    //mlx_loop(mlx_ptr);
    stockfile(argv[1], line);
}