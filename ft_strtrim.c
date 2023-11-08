/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 11:46:17 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 14:46:07 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char const *set, char c)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (set[i] != '\0' && found == 0)
	{
		if (set[i] == c)
			found++;
		i++;
	}
	return (found);
}

static int	trimmed_front(char const *string, char const *set)
{
	int	i;
	int	total_trimmed;

	i = 0;
	total_trimmed = 0;
	while (in_set(set, string[i]))
	{
		i++;
		total_trimmed++;
	}
	return (total_trimmed);
}

static int	trimmed_back(char const *string, char const *set)
{
	size_t	i;
	int		total_trimmed;

	i = ft_strlen(string) - 1;
	total_trimmed = 0;
	while (in_set(set, string[i]))
	{
		i--;
		total_trimmed++;
	}
	return (total_trimmed);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_str;
	int		s1_len;
	int		s1_found_set_f;
	int		s1_found_set_r;

	trimmed_str = 0;
	s1_len = ft_strlen(s1);
	s1_found_set_f = trimmed_front(s1, set);
	s1_found_set_r = trimmed_back(s1, set);
	if (s1_len < 2)
		return ((char *)ft_substr(s1, 0, 0));
	if (s1_found_set_f == 0)
		trimmed_str = (char *)ft_substr(s1, s1_found_set_f, \
		s1_len - s1_found_set_r);
	else
		trimmed_str = (char *)ft_substr(s1, s1_found_set_f, \
		s1_len - s1_found_set_r - s1_found_set_f);
	return (trimmed_str);
}
