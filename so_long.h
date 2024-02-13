#ifndef SO_LONG_H
# define SO_LONG_H

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define KEY_ESC					53
# define KEY_W						13
# define KEY_A						0
# define KEY_S						1
# define KEY_D						2
# define BIT						32

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
	int 			x;
	int				y;
	struct s_stack	*next;
}	t_stack;

typedef struct s_dfs
{
	t_stack	*tmp;
	int		i;
	int		x;
	int		y;
	int		dx[4];
	int		dy[4];
}	t_dfs;

typedef struct s_head
{
	int				size;
	struct s_stack *front;
}	t_head;

typedef struct s_param
{
	char	map[50][50];

	int		ex;
	int		ey;
	int		x;
	int		y;
	int		move_cnt;
	int		fd;
	int		row;
	int		col;
	int		C;
	int		E;
	int		P;
	char	*str;

	void	*mlx;
	void	*win;
	void	*img_black;
	void	*img_wall;
	void	*img_food;
	void	*img_portal;
	void	*img_ghost;
	void	*img_pacman;

	int		img_width;
	int		img_height;
}	t_param;

int		check_map(char map[][50], t_param *param);
void	param_init(t_param *param);
void	map_init(char map[][50]);
void	create_map(char *s, char map[], t_param *param);
void	print_error(int type);
void	set_map(char map[][50], t_param *param);
void	put_img(char map[][50], t_param *param);
void	print_error(int type);

void	check_visited(char visited[][50]);
void	dfs(char visited[][50], t_param *param, t_head *head);
int		ind_check(int ind);
t_stack	*stack_pop(t_head *head);
void	add_new_node(t_head *head, int x, int y);
t_head	*head_init();
void	visited_init(char visited[][50], char map[][50]);

void	hook(t_param *param);
int		key_press(int keycode, t_param *param);
void	find_player(t_param *param, char map[][50]);
void	find_portal(t_param *param, char map[][50]);

void	move_left(t_param *param, char map[][50]);
void	move_right(t_param *param, char map[][50]);
void	move_up(t_param *param, char map[][50]);
void	move_down(t_param *param, char map[][50]);


#endif