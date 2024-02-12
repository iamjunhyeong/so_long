#ifndef SO_LONG_H
# define SO_LONG_H
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "stdlib.h"
# include "fcntl.h"
# include "unistd.h"

typedef struct s_img
{
	void *mlx;
	void *win;
	void *img1;
	void *img2;
	void *img3;
	void *img4;
	void *img5;
	void *img6;
	int img_width;
	int img_height;
}	t_img;

// mlx 구조체
typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

// image data 구조체
typedef struct s_data
{
	void 	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_param
{
	int	x;
	int	y;
}	t_param;

typedef struct s_mapinfo
{
	char	*str;
	int		fd;
	int		row;
	int		col;
	int		C;
	int		E;
	int		P;
}	t_mapinfo;

void	set_map(char map[][50]);
int		check_map(char map[][50]);
void	map_init(char map[][50]);
void	create_map(char *s, char map[], t_mapinfo *mi);
void	print_error(int type);
void	set_img(t_vars *vars, t_img *img, char map[][50]);
void	put_img(t_vars *vars, t_img *img, char map[][50]);

#endif