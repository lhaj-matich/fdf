#ifndef FDF_H
#define FDF_H

typedef struct s_point {
    int color;
    int z;
} t_point;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

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
    t_data img;
} t_fdf;

#endif