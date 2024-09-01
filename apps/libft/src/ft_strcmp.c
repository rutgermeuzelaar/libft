/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/01 15:42:22 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/09/01 19:24:45 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*p1 = (const unsigned char *)s1;
	const unsigned char	*p2 = (const unsigned char *)s2;

	while (*p1 != '\0')
	{
		if (*p1 > *p2)
		{
			return (1);
		}
		if (*p1 < *p2)
		{
			return (-1);
		}
		p1++;
		p2++;
	}
	if (*p2 != '\0')
	{
		return (-1);
	}
	return (0);
}
