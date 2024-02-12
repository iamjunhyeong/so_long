/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:28:24 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/10 19:28:24 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strndup(const char *str, size_t n)
{
	size_t	len;
	size_t	i;
	char	*copy;

	len = 0;
	i = 0;
	while (len < n && str[len])
		len++;
	copy = (char *)malloc(len + 1);
	if (!copy)
		return (NULL);
	while (len > i)
	{
		copy[i] = str[i];
		i++;
	}
	copy[len] = '\0';
	return (copy);
}

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	t_strjoin_var	var;
	int				n_cp;

	if (!s1)
		return (ft_strndup(s2, n));
	var = (struct s_strjoin_var){0, 0, 0, 0, NULL};
	while (s1[var.i++])
		var.len++;
	n_cp = n;
	while (s2[var.j++] && n_cp--)
		var.len++;
	var.str = (char *)malloc(sizeof(char) * (var.len + 1));
	if (!var.str)
		return (NULL);
	var.i = 0;
	var.j = 0;
	while (s1[var.i])
		var.str[var.n++] = s1[var.i++];
	while (s2[var.j] && n--)
		var.str[var.n++] = s2[var.j++];
	var.str[var.n] = 0;
	return ((char *)var.str);
}

t_gnl_list	*ft_lstnew(int fd)
{
	t_gnl_list	*new;

	new = (t_gnl_list *)malloc(sizeof(t_gnl_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->eof = 0;
	new->next = NULL;
	new->backup = NULL;
	return (new);
}

void	lst_delone(t_gnl_list *remove, t_gnl_list **head, t_gnl_list *tmp)
{
	tmp = *head;
	if (!tmp)
		return ;
	if (remove == tmp)
	{
		*head = tmp->next;
		if (remove->backup)
			free(remove->backup);
		free(remove);
		return ;
	}
	while (tmp && remove)
	{
		if (tmp->next == remove)
		{
			tmp->next = remove->next;
			if (remove->backup)
				free(remove->backup);
			free(remove);
			break ;
		}
		tmp = tmp->next;
	}
}

int	find_newline(char *line)
{
	int	n;

	n = 0;
	while (line[n] != 0)
	{
		if (line[n] == '\n')
			return (n + 1);
		n++;
	}
	return (0);
}
