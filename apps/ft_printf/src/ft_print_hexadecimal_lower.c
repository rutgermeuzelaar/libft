/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hexadecimal_lower.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 16:46:48 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:43:49 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/libft.h"
#include "libft/ft_printf.h"

size_t	ft_print_hexadecimal_lower_ui(unsigned int number)
{
	size_t	string_length;
	size_t	base_characters_string_length;
	char	*base_characters;

	base_characters = "0123456789abcdef";
	base_characters_string_length = ft_strlen(base_characters);
	string_length = ft_ultoa_base(number, base_characters, \
	base_characters_string_length, 1);
	return (string_length);
}

size_t	ft_print_hexadecimal_lower_ul(unsigned long number)
{
	size_t	string_length;
	size_t	base_characters_string_length;
	char	*base_characters;

	base_characters = "0123456789abcdef";
	base_characters_string_length = ft_strlen(base_characters);
	string_length = ft_ultoa_base(number, base_characters, \
	base_characters_string_length, 1);
	return (string_length);
}
