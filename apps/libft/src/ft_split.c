/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 15:14:15 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 16:17:57 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft/libft.h"

static int	get_substring_len(char *s, char delimiter, size_t index)
{
	int		substring_len;
	size_t	i;

	i = 0;
	substring_len = 0;
	while (s[index + i] != '\0')
	{
		if (s[index + i] != delimiter)
		{
			while (s[index + i] != delimiter && s[index + i] != '\0')
			{
				substring_len++;
				i++;
			}
			return (substring_len);
		}
		i++;
	}
	return (substring_len);
}

static int	get_total_substrings(char *s, char delimiter)
{
	size_t	i;
	int		substring_total;

	i = 0;
	substring_total = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter)
		{
			substring_total++;
			while (s[i] != delimiter && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (substring_total);
}

static char	**create_arr_of_ptrs(const int size)
{
	char		**arr_of_ptrs;

	arr_of_ptrs = NULL;
	if (size == 0)
	{
		return (NULL);
	}
	arr_of_ptrs = ft_calloc(size + 1, sizeof(char *));
	if (arr_of_ptrs == 0)
		return (NULL);
	return (arr_of_ptrs);
}

static void	free_arr_of_ptrs(char **arr_of_ptrs, const int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr_of_ptrs[i]);
		i++;
	}
	free(arr_of_ptrs);
}

char	**ft_split(char const *s, char c)
{
	const int	total_substrings = get_total_substrings((char *)s, c);
	int			i;
	int			j;
	int			substring_len;
	char		**arr_of_ptrs;

	i = 0;
	j = -1;
	arr_of_ptrs = create_arr_of_ptrs(total_substrings);
	if (arr_of_ptrs == 0)
		return (NULL);
	while (++j < total_substrings)
	{
		while (s[i] == c)
			i++;
		substring_len = get_substring_len((char *)s, c, i);
		arr_of_ptrs[j] = ft_substr(s, i, substring_len);
		if (arr_of_ptrs[j] == 0)
		{
			free_arr_of_ptrs(arr_of_ptrs, total_substrings);
			return (NULL);
		}
		i += substring_len;
	}
	return (arr_of_ptrs);
}
