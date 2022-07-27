/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:47:51 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/21 13:13:39 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	if (s[i] != c && s[i])
	{
		words++;
		i++;
	}
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

static char	*make_string(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free_array(char **buffer, int i)
{
	int	j;

	if (buffer[i])
		return ;
	j = 0;
	while (j < i)
	{
		free(buffer[j]);
		j++;
	}
	free(buffer);
}

char	**ft_split(char const *s, char c)
{
	char			**buffer;
	int				i;

	if (!s)
		return (NULL);
	buffer = (char **)ft_calloc((count(s, c) + 1), sizeof(char *));
	if (!buffer)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			buffer[i] = make_string(s, c);
			ft_free_array(buffer, i);
			if (!buffer[i])
				return (NULL);
			while (*s && *s != c)
				s++;
		}
		i++;
	}
	return (buffer);
}
