/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 09:20:04 by iniska            #+#    #+#             */
/*   Updated: 2023/11/13 11:27:21 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*chr;
	char	*f;
	int		n;

	chr = (char *)s;
	f = (NULL);
	n = 0;
	while (*chr != '\0')
	{
		if (*chr == (char)c)
		{
			f = chr;
			chr++;
			n = 1;
		}
		else
			chr++;
	}
	if ((char)c == '\0')
		return (chr);
	else
		return (f);
}
