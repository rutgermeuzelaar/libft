/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:46:05 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:49:43 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	multiplication;

	ptr = 0;
	multiplication = nmemb * size;
	if (size != 0 && multiplication / size != nmemb)
		return (0);
	ptr = malloc(multiplication);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, multiplication);
	return (ptr);
}
