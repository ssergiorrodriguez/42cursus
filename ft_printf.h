/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:19:35 by serodrig          #+#    #+#             */
/*   Updated: 2022/08/04 16:20:29 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *str, ...);

void	ft_putchar(char c, int *len);

void	ft_putstr(char *str, int *len);

void	ft_putnd(int nd, int *len);

void	ft_putui(unsigned int n, int *len);

void	ft_putnhx(unsigned long long nhx, const char c, int *len);

void	ft_printc(va_list args, int *len);

void	ft_prints(va_list args, int *len);

void	ft_printp(va_list args, const char c, int *len);

void	ft_printx(va_list args, const char c, int *len);

void	ft_printdiu(va_list args, const char c, int *len);

void	ft_validateformat(va_list args, const char c, int *len);

#endif
