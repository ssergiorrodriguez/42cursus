/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:37:34 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/19 18:12:52 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	n_len;

	i = 0;
	n_len = ft_strlen(needle);
	if (!needle[0] || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		k = i + j;
		while (haystack[k] && needle[j] && haystack[k] == needle[j] && k < len)
		{
			j++;
			k++;
		}
		if (j == n_len)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
