#include "points.h"
#ifndef FDF_H
#define FDF_H

typedef struct s_fdf
{
    t_point **matrix;
    void	*mlx;
	void	*mlx_win;
    int width;
    int height;
    int zoom;
    int shift;
    int k;
} t_fdf;

#endif