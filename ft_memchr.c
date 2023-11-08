/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:43:14 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/10/10 09:43:14 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*s_ptr;

	i = 0;
	s_ptr = s;
	c = (unsigned char)c;
	while (i < n)
	{
		if (s_ptr[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
