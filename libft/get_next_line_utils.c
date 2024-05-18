/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:27:34 by iniska            #+#    #+#             */
/*   Updated: 2023/12/11 08:45:47 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	setitfree(t_list **list, t_list *clean_line, char *buf)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->s_line);
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (clean_line == 0 || buf == 0)
		return ;
	if (clean_line->s_line[0])
		*list = clean_line;
	else
	{
		free(buf);
		free(clean_line);
	}
}

t_list	*find_last_line(t_list *list)
{
	if (list == NULL)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	size_of_line(t_list *list)
{
	int	i;
	int	len;

	len = 0;
	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list->s_line[i])
		{
			if (list->s_line[i] == '\n')
			{
				len++;
				return (len);
			}
			i++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

int	list_the_line(t_list **list, char *line)
{
	t_list	*new_line;
	t_list	*last_line;

	last_line = find_last_line(*list);
	new_line = malloc(sizeof(t_list));
	if (new_line == NULL)
		return (-1);
	if (last_line == NULL)
		*list = new_line;
	else
		last_line->next = new_line;
	new_line->s_line = line;
	new_line->next = NULL;
	return (0);
}

int	look_slash_n(t_list *list)
{
	int	i;

	if (list == NULL)
		return (0);
	while (list)
	{
		i = 0;
		while (list -> s_line[i] && i < BUFFER_SIZE)
		{
			if (list->s_line[i] == '\n')
				return (1);
			i++;
		}
		list = list->next;
	}
	return (0);
}
