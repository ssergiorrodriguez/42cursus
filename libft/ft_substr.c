/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:33:21 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/20 18:08:07 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	i = (size_t)start;
	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		len = 0;
	else if (ft_strlen(s + start) < len)
		len = ft_strlen(s);
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!buffer)
		return (NULL);
	while (j < len && s[i])
	{
		buffer[j] = s[i];
		i++;
		j++;
	}
	buffer[j] = 0;
	return (buffer);
}
