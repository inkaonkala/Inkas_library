/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:46:04 by iniska            #+#    #+#             */
/*   Updated: 2023/11/07 10:02:01 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	charchk(char const *set, char const c)
{
	size_t	i;

	i = 0;
	if (!set)
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*newstr(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*copy;
	int		i;
	int		start;
	int		end;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && charchk(set, *(s1 + start)))
		start ++;
	end = ft_strlen(s1);
	while (end > start && charchk(set, *(s1 + (end -1))))
		end--;
	copy = newstr(end - start);
	if (!copy)
		return (NULL);
	while ((start + i) < end)
	{
		copy[i] = s1[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
