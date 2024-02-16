/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:20:58 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/16 22:49:29 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define PRESS_RED_BUTTON			17

# include <math.h>
# include <mlx.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_stack
{
	int				x;
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
	struct s_stack	*top;
}	t_head;

typedef struct s_param
{
	char	map[50][50];
	char	*map_name;

	int		line_len;
	int		ex;
	int		ey;
	int		x;
	int		y;
	int		move_cnt;
	int		fd;
	int		row;
	int		col;
	int		c;
	int		e;
	int		p;
	char	*str;

	void	*mlx;
	void	*win;
	void	*img_black;
	void	*img_wall;
	void	*img_food;
	void	*img_por;
	void	*img_pac;

	int		img_w;
	int		img_h;

	void	*img_zero;
	void	*img_one;
	void	*img_two;
	void	*img_thr;
	void	*img_fou;
	void	*img_fiv;
	void	*img_six;
	void	*img_sev;
	void	*img_eig;
	void	*img_nin;
}	t_param;

int		check_map(char map[][50], t_param *param);
void	param_init(t_param *param, char *map);
void	map_init(char map[][50]);
void	create_map(char *s, char map[], t_param *param);
void	print_error(int type);
void	set_map(char map[][50], t_param *param);
void	put_img(char map[][50], t_param *param);
void	print_error(int type);
int		end_game(t_param *param);
void	finish_game(t_param *param);
void	map_size_check(t_param *param);
void	put_number(t_param *param);
void	img_init(t_param *param);
void	my_put_image(t_param *p, char c, int i, int j);
void	*get_xpm_file(char *str, t_param *p);

void	check_visited(char visited[][50]);
void	dfs(char visited[][50], t_head *head);
int		ind_check(int ind);
void	*get_xpm(int num, t_param *param);
t_stack	*stack_pop(t_head *head);
void	add_new_node(t_head *head, int x, int y);
t_head	*head_init(void);
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