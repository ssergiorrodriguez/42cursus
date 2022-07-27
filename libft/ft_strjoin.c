/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:46:41 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/19 18:08:07 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*buffer;
	unsigned int	i;
	unsigned int	l1;
	unsigned int	l2;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	buffer = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!buffer)
		return (NULL);
	while (*s1)
		buffer[i++] = *s1++;
	while (*s2)
		buffer[i++] = *s2++;
	buffer[i] = '\0';
	return (buffer);
}
