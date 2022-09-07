/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:19:24 by serodrig          #+#    #+#             */
/*   Updated: 2022/08/04 16:26:03 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

void	ft_printc(va_list args, int *len)
{
	int	x;

	x = va_arg(args, int);
	ft_putchar(x, len);
}

void	ft_prints(va_list args, int *len)
{
	char	*x;

	x = va_arg(args, char *);
	ft_putstr(x, len);
}

void	ft_printp(va_list args, const char c, int *len)
{
	unsigned long long	x;

	x = va_arg(args, unsigned long long);
	ft_putstr("0x", len);
	ft_putnhx(x, c, len);
}

void	ft_printx(va_list args, const char c, int *len)
{
	unsigned int	x;

	x = va_arg(args, unsigned int);
	ft_putnhx(x, c, len);
}

void	ft_printdiu(va_list args, const char c, int *len)
{
	int				x;
	unsigned int	y;

	if (c == 'u')
	{
		y = va_arg(args, unsigned int);
		ft_putui(y, len);
	}
	if (c == 'd' || c == 'i')
	{
		x = va_arg(args, int);
		ft_putnd(x, len);
	}
}
