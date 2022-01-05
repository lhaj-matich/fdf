#include "points.h"
#ifndef FDF_H
#define FDF_H

typedef struct s_fdf
{
    int width;
    int height;
    int zoom;
    int z;
    int color;
    int shift;
    void	*mlx;
	void	*mlx_win;
    t_point **matrix;
} t_fdf;

#endif