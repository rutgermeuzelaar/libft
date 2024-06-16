/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/10 09:46:05 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:42:47 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

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
