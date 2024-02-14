#include "../so_long.h"

void	find_portal(t_param *param, char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50 && map[i][j] != 'E')
			j++;
		if (map[i][j] == 'E')
			break ;
		i++;
	}
	param->ex = i;
	param->ey = j;
}

void	find_player(t_param *param, char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50 && map[i][j] != 'P')
			j++;
		if (map[i][j] == 'P')
			break ;
		i++;
	}
	param->x = i;
	param->y = j;
}

void	visited_init(char visited[][50], char map[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			if (map[i][j] != '0')
				visited[i][j] = 1;
			else
				visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_head	*head_init()
{
	t_head	*tmp;

	tmp = (t_head *)malloc(sizeof(t_head));
	if (!tmp)
		return (NULL);
	tmp->front = NULL;
	tmp->size = 0;
	return (tmp);
}

void	add_new_node(t_head *head, int x, int y)
{
	t_stack *new;
	t_stack *tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		print_error(2);
	new->x = x;
	new->y = y;
	new->next = NULL;
	if (head->front == NULL)
	{
		head->front = new;
		head->size++;
		return ;
	}
	tmp = head->front;
	while (tmp)
	{
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	head->size++;
	tmp->next = new;
}

t_stack	*stack_pop(t_head *head)
{
	t_stack	*tmp;

	tmp = head->front;
	while (tmp->next)
		tmp = tmp->next;
	head->size--;
	return (tmp);
}

#include <stdio.h>
int	ind_check(int ind)
{
	if (0 <= ind && ind < 50)
		return (1);
	return (0);
}

void	dfs_init(t_dfs *vars)
{
	vars->dx[0] = 1;
	vars->dx[1] = -1;
	vars->dx[2] = 0;
	vars->dx[3] = 0;
	vars->dy[0] = 0;
	vars->dy[1] = 0;
	vars->dy[2] = 1;
	vars->dy[3] = -1;
	vars->x = 0;
	vars->y = 0;
}

void	dfs(char visited[][50], t_param *param, t_head *head)
{
	t_dfs	v;

	dfs_init(&v);

	add_new_node(head, param->x, param->y);
	visited[param->x][param->y] = 1;
	while (head->size)
	{
		v.i = 0;
		v.tmp = stack_pop(head);
		v.x = v.tmp->x;
		v.y = v.tmp->y;
		while (v.i < 4)
		{
			if (!ind_check(v.x + v.dx[v.i]) || !ind_check(v.y + v.dy[v.i]))
				v.i++;
			else if (visited[v.x + v.dx[v.i]][v.y + v.dy[v.i]])
				v.i++;
			else
			{
				// ft_printf("%d %d\n", v.x + v.dx[v.i], v.y + v.dy[v.i]);
				add_new_node(head, v.x + v.dx[v.i], v.y + v.dy[v.i]);
				visited[v.x + v.dx[v.i]][v.y + v.dy[v.i]] = 1;
				v.i++;
			}
		}
	}
}

void	check_visited(char visited[][50])
{
	int i;
	int j;

	i = 0;
	while (i < 50)
	{
		j = 0;
		while (j < 50)
		{
			ft_printf("%d", visited[i][j]);
			// if (!visited[i][j])
			// 	print_error(1);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	check_map(char map[][50], t_param *param)
{
	char	visited[50][50];
	t_head	*head;

	head = head_init();
	if (!head)
		print_error(2);
	visited_init(visited, map);
	dfs(visited, param, head);
	check_visited(visited);
	return (1);
}

int main()
{
	char map[6][34] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
						1,'E',0,0,0,0,0,0,0,0,0,0,0,0,0,'C',0,0,0,0,0,'C',0,0,0,0,0,0,0,0,0,0,0,1,
						1,0,1,0,0,1,0,1,0,0,1,0,0,0,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
						1,0,1,0,0,1,0,0,1,0,1,0,1,0,1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,1,0,1,0,1,
						1,'P',0,0,0,0,0,0,0,'C',0,0,'C',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,'C',1,
						1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

}