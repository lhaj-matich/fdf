#ifndef DRAW_H
#define DRAW_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void ft_draw_line(t_data *img, t_fdf *data ,float x, float y, float x1, float y1);
void ft_draw_line(t_data *img, t_fdf *data,int x0, int y0, int x1, int y1);
void    ft_zoom(int *x, int *y, int *x1, int *y1, t_fdf *data);
#endif