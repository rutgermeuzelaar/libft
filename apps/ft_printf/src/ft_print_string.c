/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_string.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:54:38 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:30 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_string(char *string)
{
	size_t	string_length;
	char	*null_string;

	null_string = "(null)";
	if (string == NULL)
		string = null_string;
	string_length = ft_strlen(string);
	ft_putstr_fd(string, 1);
	return (string_length);
}
