/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 20:44:26 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:43:49 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	str_len;

	str_len = ft_strlen(s);
	write(fd, s, str_len);
	ft_putchar_fd('\n', fd);
}
