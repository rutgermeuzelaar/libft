/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/23 13:05:33 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 16:16:56 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE needs to be greater than 0."
# endif
# include <stddef.h>

int		set_buffer(char **buffer, int fd);
char	*create_line(char *line, char **buffer);
char	*divide_remainder(char **buffer, int chars_to_newline);
char	*get_next_line(int fd);

size_t	null_or_strlen(const char *s);
int		get_chars_to_newline(char *string);
char	*join_buffer(char *line, char *buffer);
char	*string_slice(char *s, unsigned int start, size_t len);

#endif