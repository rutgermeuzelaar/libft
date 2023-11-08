/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   memmove.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:50:30 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/10/04 13:56:31 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;
	int			i;

	dest_ptr = dest;
	src_ptr = src;
	i = n - 1;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (dest_ptr > src_ptr)
	{
		while (i >= 0)
		{
			dest_ptr[i] = src_ptr[i];
			i--;
		}
		return (dest);
	}
	return (ft_memcpy(dest, src, n));
}
