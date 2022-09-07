/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:19:24 by serodrig          #+#    #+#             */
/*   Updated: 2022/08/04 16:26:20 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	*len += 1;
}

void	ft_putstr(char *str, int *len)
{
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (*str)
		ft_putchar(*str++, len);
}

void	ft_putnd(int n, int *len)
{
	long long	nd;

	nd = (long long)n;
	if (nd < 0)
	{
		ft_putchar('-', len);
		nd *= -1;
	}
	if (nd >= 10)
	{
		ft_putnd(nd / 10, len);
		nd = nd % 10;
	}
	ft_putchar(('0' + nd), len);
}

void	ft_putui(unsigned int n, int *len)
{
	if (n >= 10)
	{
		ft_putnd(n / 10, len);
		n = n % 10;
	}
	ft_putchar(('0' + n), len);
}

void	ft_putnhx(unsigned long long nhx, const char c, int *len)
{
	if (nhx >= 16)
		ft_putnhx(nhx / 16, c, len);
	if (c == 'X')
		ft_putchar("0123456789ABCDEF"[nhx % 16], len);
	if (c == 'x' || c == 'p')
		ft_putchar("0123456789abcdef"[nhx % 16], len);
}
