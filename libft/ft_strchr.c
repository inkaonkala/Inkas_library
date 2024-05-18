/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:17:09 by iniska            #+#    #+#             */
/*   Updated: 2023/10/31 09:35:40 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*chr;

	chr = (char *)str;
	while (*chr != (char)c)
	{
		if (*chr == '\0')
			return (NULL);
		chr++;
	}
	return (chr);
}
