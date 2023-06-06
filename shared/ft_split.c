/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:42:25 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 10:57:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n && *s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

static int	width(char const *s, char c)
{
	int	count;

	if (!s)
		return (0);
	count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count);
}

static char	**freearray(char **array, int width)
{
	int	i;

	i = -1;
	while (++i < width && array[i] != 0)
		free(array[i]);
	free(array);
	return (0);
}

static int	worddup(char *s, char c, int i)
{
	int	j;

	j = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i + j] != '\0' && s[i + j] != c)
		j++;
	return (j);
}

/*
Splits a string into an array of substrings based on a delimiter.
@param s The string to split.
@param c The delimiter character.
@return An array of substrings.
*/
char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	array = ft_calloc(sizeof(char *), width(s, c) + 1);
	if (!array)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < width(s, c))
	{
		k = 0;
		array[i] = ft_calloc(sizeof(char), worddup((char *)s, c, j) + 1);
		if (!array[i])
			return (freearray(array, i));
		while (s[j] == c && s[j] != '\0')
			j++;
		while (s[j] != c && s[j] != '\0')
			array[i][k++] = s[j++];
	}
	return (array);
}
