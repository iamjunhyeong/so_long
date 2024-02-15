/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:04:28 by junhyeop          #+#    #+#             */
/*   Updated: 2024/02/15 17:44:13 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_new_node(t_head *head, int x, int y)
{
	t_stack	*new;
	t_stack	*tmp;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		print_error(2);
	new->x = x;
	new->y = y;
	if (head->top == NULL)
	{
		new->next = NULL;
		head->top = new;
	}
	else
	{
		tmp = head->top;
		head->top = new;
		new->next = tmp;
	}
	head->size++;
}

t_stack	*stack_pop(t_head *head)
{
	t_stack	*pop;

	pop = head->top;
	head->top = pop->next;
	head->size--;
	return (pop);
}

void	freeall(t_head *head)
{
	if (!head)
		return ;
	free(head);
}

