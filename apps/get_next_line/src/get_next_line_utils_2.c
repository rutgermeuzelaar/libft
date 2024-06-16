/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_2.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/15 20:05:17 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 20:56:39 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	set_buffer(char **buffer, int fd)
{
	int		bytes_read;

	bytes_read = 1;
	if (*buffer == NULL)
	{
		*buffer = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (*buffer == NULL)
			return (-1);
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(*buffer);
			*buffer = NULL;
		}
	}
	return (bytes_read);
}

char	*create_line(char *line, char **buffer)
{
	const int		chars_to_newline = get_chars_to_newline(*buffer);
	char			*string_to_append;

	if (chars_to_newline != -1 && chars_to_newline != BUFFER_SIZE - 1)
	{
		string_to_append = divide_remainder(buffer, chars_to_newline);
		if (string_to_append == NULL)
			return (free(line), NULL);
		line = join_buffer(line, string_to_append);
		free(string_to_append);
	}
	else
	{
		line = join_buffer(line, *buffer);
		free(*buffer);
		*buffer = NULL;
	}
	if (line == NULL)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	return (line);
}

char	*divide_remainder(char **buffer, int chars_to_newline)
{
	char	*temp_buffer;
	char	*string_to_append;

	temp_buffer = NULL;
	temp_buffer = join_buffer(temp_buffer, *buffer);
	free(*buffer);
	*buffer = NULL;
	if (temp_buffer == NULL)
		return (NULL);
	string_to_append = string_slice(temp_buffer, 0, chars_to_newline + 1);
	if (string_to_append == NULL)
		return (free(temp_buffer), NULL);
	*buffer = string_slice(temp_buffer, chars_to_newline + 1, \
	BUFFER_SIZE - chars_to_newline);
	if (*buffer == NULL)
		return (free(temp_buffer), free(string_to_append), NULL);
	if (null_or_strlen(*buffer) == 0)
	{
		free(*buffer);
		*buffer = NULL;
	}
	free(temp_buffer);
	return (string_to_append);
}
