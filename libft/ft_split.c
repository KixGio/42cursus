/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdeugeni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:56:45 by gdeugeni          #+#    #+#             */
/*   Updated: 2025/01/02 15:04:03 by gdeugeni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

static int	get_word_count(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	*get_next_word(const char **s, char c)
{
	char	*word;
	size_t	len;

	while (**s && **s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = ft_substr(*s, 0, len);
	*s += len;
	return (word);
}

char	**ft_split(const char *s, char c)
{
	char	**ret;
	int		i;
	int		words;

	if (!s)
		return (0);
	words = get_word_count(s, c);
	ret = malloc(sizeof(char *) * (words + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i < words)
	{
		ret[i] = get_next_word(&s, c);
		if (!ret[i])
		{
			while (i-- > 0)
				free(ret[i]);
			free(ret);
			return (0);
		}
		i++;
	}
	ret[i] = 0;
	return (ret);
}
