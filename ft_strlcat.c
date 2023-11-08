/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:38:07 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/10/10 09:38:07 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	i = 0;
	while (dst[i] != '\0')
	{
		if (i == size)
			return (size + src_len);
		i++;
	}
	if (i == size)
		return (size + src_len);
	dst_len = i;
	ft_strlcpy(&dst[dst_len], src, size - dst_len);
	return (dst_len + src_len);
}
