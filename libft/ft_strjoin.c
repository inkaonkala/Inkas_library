/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:51:44 by iniska            #+#    #+#             */
/*   Updated: 2023/11/10 10:58:17 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		c;
	char	*copy;

	i = 0;
	c = 0;
	copy = (char *)malloc(sizeof(char) * (ft_strlen(s1) + (ft_strlen(s2) +1)));
	if (!copy)
		return (NULL);
	while (s1[i] != '\0')
	{
		copy[c] = s1[i];
		c++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		copy[c] = s2[i];
		c++;
		i++;
	}
	copy[c] = '\0';
	return (copy);
}
