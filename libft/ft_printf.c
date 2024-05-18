/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iniska <iniska@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:04:09 by iniska            #+#    #+#             */
/*   Updated: 2024/05/02 18:15:53 by iniska           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_f(const char *format, int totals, va_list ap)
{
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == '%')
				totals += printchar('%');
			else
				totals += ft_form(*(format), ap);
			if (totals < 0)
				return (-1);
		}
		else
		{
			if (write(1, format, 1) == -1)
				return (-1);
			totals ++;
		}
		format++;
	}
	return (totals);
}

int	ft_printf(const char *format, ...)
{
	int		totals;
	va_list	ap;

	totals = 0;
	va_start(ap, format);
	totals = print_f(format, totals, ap);
	if (totals < 0)
		return (-1);
	va_end(ap);
	return (totals);
}
