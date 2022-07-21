/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:48:09 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/19 12:59:19 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	length(long ng)
{
	int	len;

	len = 0;
	if (ng == 0)
		len = 1;
	else if (ng < 0)
	{
		ng = -ng;
		len++;
	}
	while (ng > 0)
	{
		ng = ng / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long			ng;
	char			*buffer;
	unsigned int	len;

	ng = n;
	len = length(ng);
	buffer = (char *)malloc(sizeof(char) * (length(ng) + 1));
	if (!buffer)
		return (NULL);
	buffer[len--] = '\0';
	if (ng == 0)
		buffer[0] = '0';
	if (ng < 0)
	{
		buffer[0] = '-';
		ng = -ng;
	}
	while (ng > 0)
	{
		buffer[len--] = 48 + (ng % 10);
		ng = ng / 10;
	}
	return (buffer);
}
