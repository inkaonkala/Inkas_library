/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:40:11 by iniska            #+#    #+#             */
/*   Updated: 2023/11/07 10:08:08 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*str_new(size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;
	char	*copy;

	if (s == NULL)
		return (NULL);
	if (*s == '\0')
	{
		str = str_new(0);
		if (!str)
			return (NULL);
		*str = 0;
		return (str);
	}
	str = str_new(ft_strlen(s));
	if (!str)
		return (NULL);
	i = 0;
	copy = str;
	while (*s)
		*str++ = f(i++, *s++);
	*str = '\0';
	return (copy);
}
