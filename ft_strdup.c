/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:47:14 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 14:21:59 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	size;
	char	*ptr;

	size = ft_strlen(s) + 1;
	ptr = malloc(size * sizeof(char));
	if (ptr == 0)
		return (0);
	ft_memcpy(ptr, s, size);
	return (ptr);
}
