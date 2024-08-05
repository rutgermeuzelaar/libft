/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 15:23:44 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/05 15:24:17 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v');
}