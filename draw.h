#ifndef DRAW_H
#define DRAW_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	ft_draw_line(int x0,  int y0 , int x1, int y1);

#endif