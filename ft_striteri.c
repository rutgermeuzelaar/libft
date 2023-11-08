/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 17:55:50 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 15:04:24 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	str_len;

	i = 0;
	str_len = ft_strlen(s);
	while (i < str_len)
	{
		f(i, &s[i]);
		i++;
	}
}
