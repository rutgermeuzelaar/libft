/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ultoa_base.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 15:53:22 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:23 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_ultoa_base(size_t number, char *base_characters, \
size_t base_len, size_t number_length)
{
	size_t		modulo;

	modulo = number % base_len;
	number = number / base_len;
	if (number)
		number_length = ft_ultoa_base(number, base_characters, \
		base_len, number_length + 1);
	ft_putchar_fd(base_characters[modulo], 1);
	return (number_length);
}
