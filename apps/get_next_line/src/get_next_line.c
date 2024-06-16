/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:09:45 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 20:50:55 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0)
		return (NULL);
	while (get_chars_to_newline(line) == -1)
	{
		bytes_read = set_buffer(&buffer, fd);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free(line), NULL);
		line = create_line(line, &buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
