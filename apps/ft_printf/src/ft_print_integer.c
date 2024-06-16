/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_integer.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/10 19:26:36 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/15 19:12:32 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	get_arr_len(int n)
{
	int	div;
	int	len;

	div = 10;
	len = 0;
	if (n < 0)
		div = -div;
	if (n < 10 && div != -10)
		return (1);
	while (n / div)
	{
		n = n / div;
		len++;
	}
	if (n != 0)
		len++;
	return (len);
}

int	ft_print_integer(int number)
{
	int	number_len;

	number_len = get_arr_len(number);
	if (number < 0)
		number_len++;
	ft_putnbr_fd(number, 1);
	return (number_len);
}
