/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_unsigned_decimal.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 16:32:08 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:28 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_print_unsigned_decimal(unsigned int unsigned_decimal)
{
	size_t	string_length;
	size_t	base_characters_string_length;
	char	*base_characters;

	base_characters = "0123456789";
	base_characters_string_length = ft_strlen(base_characters);
	string_length = ft_ultoa_base(unsigned_decimal, base_characters, \
	base_characters_string_length, 1);
	return (string_length);
}
