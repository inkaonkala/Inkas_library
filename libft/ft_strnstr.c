/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:12:54 by iniska            #+#    #+#             */
/*   Updated: 2023/11/10 16:23:06 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t loc)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (*needle == '\0' || needle == NULL)
		return ((char *)haystack);
	while (haystack[i] != '\0' && needle[n] != '\0' && i < loc)
	{
		n = 0;
		if (haystack[i] == needle[0])
		{
			while (haystack[i + n] == needle[n] && (i + n) < loc)
			{
				if (needle[n + 1] == '\0')
					return ((char *)haystack + i);
				n++;
			}
		}
		i++;
	}
	return (NULL);
}
