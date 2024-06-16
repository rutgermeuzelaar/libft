/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 17:23:02 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 19:59:53 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "../../../include/libft.h"

int		ft_print_character(char character);
int		ft_print_string(char *string);
size_t	ft_print_void_pointer(void *void_pointer);
int		ft_print_integer(int number);
size_t	ft_ultoa_base(size_t number, char *base_characters, \
		size_t base_len, size_t number_length);
size_t	ft_print_unsigned_decimal(unsigned int unsigned_decimal);
size_t	ft_print_hexadecimal_lower_ui(unsigned int number);
size_t	ft_print_hexadecimal_lower_ul(unsigned long number);
size_t	ft_print_hexadecimal_upper(unsigned int number);
int		ft_printf(const char *fmt, ...);
#endif