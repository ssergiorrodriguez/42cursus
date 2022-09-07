/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:19:24 by serodrig          #+#    #+#             */
/*   Updated: 2022/08/04 15:59:57 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_validateformat(va_list args, const char c, int *len)
{
	if (c == 'c')
		ft_printc(args, len);
	else if (c == 's')
		ft_prints(args, len);
	else if (c == 'p')
		ft_printp(args, c, len);
	else if (c == 'X' || c == 'x')
		ft_printx(args, c, len);
	else if (c == 'd' || c == 'i' || c == 'u')
		ft_printdiu(args, c, len);
	else if (c == '%')
		ft_putchar('%', len);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			ft_validateformat(args, format[i + 1], &len);
			i++;
		}
		else
			ft_putchar(format[i], &len);
		i++;
	}
	va_end(args);
	return (len);
}
