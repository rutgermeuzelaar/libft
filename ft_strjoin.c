/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/25 11:29:38 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 14:44:14 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	joined_total;
	char	*joined_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined_total = s1_len + s2_len + 1;
	joined_str = malloc((joined_total) * sizeof(char));
	if (joined_str == 0)
		return (0);
	ft_strlcpy(joined_str, s1, joined_total);
	ft_strlcat(joined_str, s2, joined_total);
	return (joined_str);
}
