/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matesant <matesant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 09:47:21 by matesant          #+#    #+#             */
/*   Updated: 2023/11/16 17:46:32 by matesant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *str, char limiter)
{
	size_t	index;
	size_t	counter;

	index = 0;
	counter = 0;
	while (str[index])
	{
		while ((str[index]) && (str[index] == limiter))
			index++;
		if (str[index])
			counter++;
		while ((str[index]) && (str[index] != limiter))
			index++;
	}
	return (counter);
}

static size_t	ft_len_substring(char const *str, int start, char limiter)
{
	size_t	length;

	length = 0;
	while ((str[start]) && (str[start] != limiter))
	{
		start++;
		length++;
	}
	return (length);
}

char	**ft_split(char const *s, char c)
{
	int		number_words;
	int		len_substr;
	int		index;
	int		start;
	char	**words_array;

	if (s == NULL)
		return (0);
	number_words = ft_count_words(s, c);
	words_array = (char **)ft_calloc((number_words + 1), sizeof(char *));
	if (words_array == NULL)
		return (NULL);
	index = 0;
	start = 0;
	while (index < number_words)
	{
		while ((s[start]) && (s[start] == c))
			start++;
		len_substr = ft_len_substring(s, start, c);
		words_array[index] = ft_substr(s, start, len_substr);
		start = start + len_substr;
		index++;
	}
	return (words_array);
}
