/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_1.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 14:57:10 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 20:26:24 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

size_t	null_or_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	get_chars_to_newline(char *string)
{
	int	i;

	i = 0;
	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

char	*join_buffer(char *line, char *buffer)
{
	const size_t	line_len = null_or_strlen(line);
	const size_t	buffer_len = null_or_strlen(buffer);
	const size_t	joined_total = line_len + buffer_len + 1;
	char			*joined_str;
	size_t			i;

	joined_str = (char *)ft_calloc(joined_total, sizeof(char));
	if (joined_str == NULL)
		return (free(line), NULL);
	i = 0;
	while (i < joined_total - 1)
	{
		if (i < line_len)
			joined_str[i] = line[i];
		else
			joined_str[i] = buffer[i - line_len];
		i++;
	}
	free(line);
	return (joined_str);
}

char	*string_slice(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	size_t	substring_len;

	i = 0;
	substring = 0;
	substring_len = null_or_strlen(s);
	if (start > substring_len)
		substring_len = 0;
	else
		substring_len = null_or_strlen(&s[start]);
	if (len > substring_len)
		len = substring_len;
	substring = (char *)ft_calloc((len + 1), sizeof(char));
	if (substring == NULL)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
