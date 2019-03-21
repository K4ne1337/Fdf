#ifndef FDF_H
#define FDF_H

#include "../libft/libft.h"

typedef struct s_point
{
    int x;
    int y;
    int z;
}              t_point;

void    stockfile(char *filename, char *line);
char    **creategrid(int nbline, int col);
void	displaygrid(char **grid, int nbline, int col);
int	    char_number(char *str);

#endif