/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/07 17:22:45 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:03:16 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	conversion_table(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_print_character(va_arg(*ap, int)));
	if (type == 's')
		return (ft_print_string(va_arg(*ap, char *)));
	if (type == 'p')
		return (ft_print_void_pointer(va_arg(*ap, void *)));
	if (type == 'd' || type == 'i')
		return (ft_print_integer(va_arg(*ap, int)));
	if (type == 'u')
		return (ft_print_unsigned_decimal(va_arg(*ap, unsigned long)));
	if (type == 'x')
		return (ft_print_hexadecimal_lower_ui(va_arg(*ap, size_t)));
	if (type == 'X')
		return (ft_print_hexadecimal_upper(va_arg(*ap, size_t)));
	if (type == '%')
		return (ft_putchar_fd('%', 1), 1);
	else
		return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		num_of_characters_printed;
	size_t	i;
	size_t	fmt_len;

	fmt_len = ft_strlen(fmt);
	num_of_characters_printed = 0;
	i = 0;
	va_start(ap, fmt);
	while (fmt[i] != '\0' && i < fmt_len)
	{
		if (fmt[i] == '%')
		{
			i++;
			num_of_characters_printed += conversion_table(fmt[i], &ap);
		}
		else
		{
			ft_putchar_fd(fmt[i], 1);
			num_of_characters_printed++;
		}
		i++;
	}
	va_end(ap);
	return (num_of_characters_printed);
}
