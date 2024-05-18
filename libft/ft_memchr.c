/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 09:40:50 by iniska            #+#    #+#             */
/*   Updated: 2023/10/31 09:40:32 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	size_t	l;
	char	*n;
	char	i;

	l = 0;
	i = c;
	n = (char *)s;
	while (l < len)
	{
		if (*n == i)
		{
			return ((void *)n);
		}
		n++;
		l++;
	}
	return (NULL);
}
