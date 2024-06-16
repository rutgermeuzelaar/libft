/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_hexadecimal_upper.c                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/16 16:51:34 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:34 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_print_hexadecimal_upper(unsigned int number)
{
	size_t	string_length;
	size_t	base_characters_string_length;
	char	*base_characters;

	base_characters = "0123456789ABCDEF";
	base_characters_string_length = ft_strlen(base_characters);
	string_length = ft_ultoa_base(number, base_characters, \
	base_characters_string_length, 1);
	return (string_length);
}
