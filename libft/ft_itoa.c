/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:58:32 by iniska            #+#    #+#             */
/*   Updated: 2023/11/10 14:39:44 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	nbr_len(int n)
{
	int	numlen;

	numlen = 0;
	if (n < 1)
		numlen ++;
	while (n)
	{
		n /= 10;
		numlen++;
	}
	return (numlen);
}

static char	*doit(int count, int neg, char *str, long nu)
{
	str[count] = '\0';
	if (nu < 0)
	{
		neg = 1;
		nu *= -1;
	}
	while (count > 0)
	{
		*(str + count -1) = nu % 10 + '0';
		nu /= 10;
		count--;
	}
	if (neg == 1)
		*str = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		count;
	int		neg;
	char	*str;
	char	*final;
	long	nu;

	neg = 0;
	nu = (long)n;
	count = nbr_len(nu);
	str = (char *)malloc(sizeof(char) * (nbr_len(n) + 1));
	if (!str)
		return (NULL);
	final = doit(count, neg, str, nu);
	return (final);
}
