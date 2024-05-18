/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 09:04:27 by iniska            #+#    #+#             */
/*   Updated: 2023/12/11 08:43:39 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	clean_list(t_list **list)
{
	t_list	*last_line;
	t_list	*new_line;
	int		i;
	int		k;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	new_line = malloc(sizeof(t_list));
	if (new_line == NULL)
		return (free(buf), -1);
	last_line = find_last_line(*list);
	i = 0;
	k = 0;
	while (last_line->s_line[i] && last_line->s_line[i] != '\n')
		i++;
	while (last_line->s_line[i] && last_line->s_line[i++])
		buf[k++] = last_line->s_line[i];
	buf[k] = '\0';
	new_line->s_line = buf;
	new_line->next = NULL;
	setitfree(list, new_line, buf);
	return (0);
}

void	copy_line(t_list *list, char *str)
{
	int	i;
	int	k;

	if (list == NULL)
		return ;
	k = 0;
	while (list)
	{
		i = 0;
		while (list->s_line[i] && i < BUFFER_SIZE)
		{
			if (list->s_line[i] == '\n')
			{
				str[k++] = '\n';
				str[k] = '\0';
				return ;
			}
			str[k++] = list->s_line[i++];
		}
		list = list->next;
	}
	str[k] = '\0';
}

char	*save_line(t_list *list)
{
	int		str_len;
	char	*str;

	if (list == NULL)
		return (NULL);
	str_len = size_of_line(list);
	str = malloc(str_len + 1);
	if (str == NULL)
		return (NULL);
	copy_line(list, str);
	return (str);
}

int	create_line(t_list **list, int fd)
{
	int		char_read;
	char	*line;

	while (!look_slash_n(*list))
	{
		line = malloc(BUFFER_SIZE + 1);
		if (line == NULL)
			return (-1);
		char_read = read(fd, line, BUFFER_SIZE);
		if (char_read < 0)
			return (free(line), -1);
		if (char_read == 0)
			return (free(line), 0);
		line[char_read] = '\0';
		if (list_the_line(list, line) < 0)
			return (free(line), -1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*nextline;
	int				status;

	if (fd < 0 || (BUFFER_SIZE <= 0))
		return (NULL);
	status = create_line(&list, fd);
	if (!list || status < 0)
		return (setitfree(&list, 0, 0), NULL);
	nextline = save_line(list);
	if (nextline == NULL)
		return (setitfree(&list, 0, 0), NULL);
	status = clean_list(&list);
	if (status < 0)
		return (free(nextline), setitfree(&list, 0, 0), NULL);
	return (nextline);
}

/*
int main() 
{
    int fd;
    char *line;

    fd = open("testytest.txt", O_RDONLY);

    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);  // Don't forget to free the allocated memory
    }

    close(fd);

    return 0;
}
*/
