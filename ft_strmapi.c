/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 17:28:48 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 15:03:58 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*return_string;
	size_t	str_len;

	i = 0;
	return_string = 0;
	str_len = ft_strlen(s);
	return_string = ft_calloc(str_len + 1, (sizeof(char)));
	if (return_string == 0)
		return (0);
	while (i < str_len)
	{
		return_string[i] = f(i, s[i]);
		i++;
	}
	return (return_string);
}
