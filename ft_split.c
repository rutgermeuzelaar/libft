/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/27 15:14:15 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 14:48:22 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	**create_arr_of_ptrs(char *s, char c)
{
	char	**arr_of_ptrs;
	int		substrings_total;

	substrings_total = get_total_substrings((char *)s, c);
	arr_of_ptrs = ft_calloc(substrings_total + 1, sizeof(char *));
	if (arr_of_ptrs == 0)
		return (0);
	return (arr_of_ptrs);
}

static void	free_arr_of_ptrs(char **arr_of_ptrs, char *s, char c)
{
	int	i;
	int	substrings_total;

	i = 0;
	substrings_total = get_total_substrings(s, c);
	while (i < substrings_total)
	{
		free(arr_of_ptrs[i]);
		i++;
	}
	free(arr_of_ptrs);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		substring_len;
	char	**arr_of_ptrs;

	i = 0;
	j = -1;
	arr_of_ptrs = create_arr_of_ptrs((char *)s, c);
	if (arr_of_ptrs == 0)
		return (0);
	while (++j < get_total_substrings((char *)s, c))
	{
		while (s[i] == c)
			i++;
		substring_len = get_substring_len((char *)s, c, i);
		arr_of_ptrs[j] = ft_substr(s, i, substring_len);
		if (arr_of_ptrs[j] == 0)
		{
			free_arr_of_ptrs(arr_of_ptrs, (char *)s, c);
			return (0);
		}
		i += substring_len;
	}
	return (arr_of_ptrs);
}
