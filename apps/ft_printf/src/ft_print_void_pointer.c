/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_void_pointer.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 16:54:50 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:26 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static size_t	ft_print_pointer_prefix(void)
{
	char	*prefix;
	size_t	string_length;

	prefix = "0x";
	string_length = ft_strlen(prefix);
	ft_putstr_fd("0x", 1);
	return (string_length);
}

size_t	ft_print_void_pointer(void *void_pointer)
{
	size_t	string_length;
	size_t	decimal_number;
	size_t	hexadecimal_lower_string_length;

	decimal_number = (size_t)void_pointer;
	string_length = 0;
	if (void_pointer == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	string_length += ft_print_pointer_prefix();
	hexadecimal_lower_string_length = \
	ft_print_hexadecimal_lower_ul(decimal_number);
	if (hexadecimal_lower_string_length == 0)
		return (0);
	return (string_length + hexadecimal_lower_string_length);
}
