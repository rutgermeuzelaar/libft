/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 11:17:41 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/03 14:02:22 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;
	size_t	substring_len;

	i = 0;
	substring = 0;
	substring_len = ft_strlen(s);
	if (start > substring_len)
		substring_len = 0;
	else
		substring_len = ft_strlen(&s[start]);
	if (len > substring_len)
		len = substring_len;
	substring = ft_calloc((len + 1), sizeof(char));
	if (substring == 0)
		return (0);
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	return (substring);
}
