/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 16:18:49 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/10/04 13:48:33 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	char				*dest_ptr;
	const char			*src_ptr;

	i = 0;
	dest_ptr = dest;
	src_ptr = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		i++;
	}
	return (dest);
}
