/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 09:29:59 by iniska            #+#    #+#             */
/*   Updated: 2023/11/19 10:43:54 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	count;
	int	n;

	count = 0;
	n = 0;
	while (*str)
	{
		if (*str != c && n == 0)
		{
			n = 1;
			count ++;
		}
		else if (*str == c)
			n = 0;
		str++;
	}
	return (count);
}

static char	*strfill(const char *s, int start, int end)
{
	char	*word;
	int		i;
	int		j;
	int		h;

	i = 0;
	j = 0;
	h = ft_strlen(s);
	word = (char *)malloc(sizeof(char) * (end + 1));
	if (!word)
		return (NULL);
	while (*(s + i) && i < h)
	{
		if (i >= start && j < end)
		{
			*(word + j) = *(s + i);
			j++;
		}
		i++;
	}
	*(word + j) = 0;
	return (word);
}

static size_t	onewordlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**dosplit(char const *s, char c, char **copy, size_t words)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words)
	{
		while (*(s + j) && *(s + j) == c)
			j++;
		*(copy + i) = strfill(s, j, onewordlen(&*(s + j), c));
		if (!*(copy + i))
		{
			while (i > 0)
			{
				i--;
				free(*(copy + i));
			}
			free (copy);
		}
		while (*(s + j) && *(s + j) != c)
			j++;
		i++;
	}
	*(copy + i) = NULL;
	return (copy);
}

char	**ft_split(char const *s, char c)
{
	char	**copy;
	size_t	words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	copy = (char **)malloc(sizeof(char *) * (words + 1));
	if (!copy)
		return (NULL);
	copy = dosplit(s, c, copy, words);
	return (copy);
}
