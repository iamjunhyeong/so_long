/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 19:28:33 by junhyeop          #+#    #+#             */
/*   Updated: 2024/01/10 19:28:33 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_strjoin_var
{
	size_t		len;
	size_t		n;
	size_t		i;
	size_t		j;
	char		*str;
}	t_strjoin_var;

typedef struct s_gnl_list
{
	int					fd;
	int					eof;
	char				*backup;
	struct s_gnl_list	*next;
}	t_gnl_list;

typedef struct s_var
{
	int			found;
	char		*line;
	t_gnl_list	*tmp;
	size_t		len_nl;
	ssize_t		len_read;
	char		*buf;
}	t_var;

t_gnl_list	*ft_lstnew(int fd);
t_gnl_list	*find_fd(t_gnl_list **head, int fd, t_gnl_list *tmp);
void		lst_delone(t_gnl_list *remove, t_gnl_list **head, t_gnl_list *tmp);
char		*read_line_ext(t_var *var);
char		*get_next_line(int fd);
char		*ft_strndup(const char *str, size_t n);
char		*ft_strnjoin(char *s1, char *s2, int n);
char		*read_line(t_var *var, int fd);
int			find_newline(char *line);
char		*load_backup(t_var *var, char **backup, char *result, char *temp);

#endif
