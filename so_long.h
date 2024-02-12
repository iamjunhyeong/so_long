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

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

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

typedef struct s_param
{
	int					x;
	int					y;
	struct s_img		*img;
	struct s_vars		*vars;
	struct s_mapinfo	*mi;
}	t_param;

void	set_map(char map[][50]);
int		check_map(char map[][50]);
void	map_init(char map[][50]);
void	create_map(char *s, char map[], t_mapinfo *mi);
void	print_error(int type);
void	set_img(t_vars *vars, t_img *img, char map[][50]);
void	put_img(t_vars *vars, t_img *img, char map[][50]);

void	hook(t_vars *vars, t_img *img, char map[][50]);
int		key_press(int keycode, t_param *param);
void	param_init(t_param *param, char map[][50]);


#endif