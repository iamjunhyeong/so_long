/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:04:28 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/13 22:23:47 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

