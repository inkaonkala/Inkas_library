/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_address.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:12:36 by iniska            #+#    #+#             */
/*   Updated: 2024/05/02 18:16:25 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_address(unsigned long n)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (n < 16)
	{
		if (printchar(symbols[n]) < 0)
			return (-1);
		return (1);
	}
	else
	{
		count = print_address(n / 16);
		return (count + print_address(n % 16));
	}
	return (-1);
}
