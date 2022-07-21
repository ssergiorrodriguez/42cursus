/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: serodrig <serodrig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 13:47:51 by serodrig          #+#    #+#             */
/*   Updated: 2022/07/20 18:04:04 by serodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(char const *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	if (s[i] != c)
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

char	**ft_split(char const *s, char c)
{
	char			**buffer;
	int				i;
	int				n_words;

	if (!s)
		return (NULL);
	i = 0;
	n_words = count(s, c);
	buffer = (char **)malloc(sizeof(char *) * (n_words + 1));
	if (!buffer)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			buffer[i] = make_string(s, c);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	buffer[i] = NULL;
	return (buffer);
}
