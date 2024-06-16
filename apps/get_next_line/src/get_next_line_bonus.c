/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:09:45 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 20:27:05 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*buffer[FILE_DESCRIPTOR_MAX];
	char		*line;
	int			bytes_read;

	line = NULL;
	if (fd < 0 || fd > FILE_DESCRIPTOR_MAX)
		return (NULL);
	while (get_chars_to_newline(line) == -1)
	{
		bytes_read = set_buffer(&buffer[fd], fd);
		if (bytes_read == 0)
			break ;
		if (bytes_read < 0)
			return (free(line), NULL);
		line = create_line(line, &buffer[fd]);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}
