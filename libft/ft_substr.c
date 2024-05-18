/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:39:55 by iniska            #+#    #+#             */
/*   Updated: 2023/11/08 17:14:27 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		c;
	char		*sub;

	i = 0;
	c = 0;
	if (!s || start >= (size_t)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > (size_t)ft_strlen(s))
		i = (size_t)ft_strlen(s) - start;
	else
		i = len;
	sub = (char *)malloc(sizeof(char) * (i + 1));
	if (!sub || !s)
		return (NULL);
	while (start < (size_t)ft_strlen(s) && c < i)
	{
		sub[c] = s[start];
		c++;
		start++;
	}
	sub[c] = '\0';
	return (sub);
}
