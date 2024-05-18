/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:02:15 by iniska            #+#    #+#             */
/*   Updated: 2023/11/12 11:43:08 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t		dstlen;
	size_t		finallen;
	const char	*s;

	dstlen = 0;
	s = src;
	if ((!dst || !src) && !n)
		return (0);
	while (*(dst + dstlen) && dstlen < n)
		dstlen++;
	if (dstlen < n)
		finallen = dstlen + ft_strlen(s);
	else
		return (n + ft_strlen(s));
	while (*s && (dstlen + 1) < n)
	{
		*(dst + dstlen) = *s++;
		dstlen++;
	}
	*(dst + dstlen) = '\0';
	return (finallen);
}
