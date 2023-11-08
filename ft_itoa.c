/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/30 20:25:56 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/02 14:57:06 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

static char	*num_to_string(int n, int arr_len, char *arr, int start)
{
	int		div;
	int		mod;
	int		is_positive;

	is_positive = 0;
	if (n >= 0)
		is_positive = 1;
	while (start < arr_len)
	{
		div = n / 10;
		mod = n % 10;
		if (mod < 0)
			mod = -mod;
		if (div * 10 == n && mod == 0)
			arr[arr_len - start - is_positive] = 48;
		else
			arr[arr_len - start - is_positive] = mod + 48;
		n = div;
		if (n < 0 && start == 0)
			n = -div;
		start++;
	}
	return (arr);
}

char	*ft_itoa(int n)
{
	char	*return_string;
	size_t	str_len;
	int		is_negative;

	return_string = 0;
	str_len = get_arr_len(n);
	is_negative = 0;
	if (n < 0)
	{
		str_len++;
		is_negative = 1;
	}
	return_string = ft_calloc((str_len + 1), sizeof(char));
	if (return_string == 0)
		return (0);
	if (is_negative)
	{
		return_string[0] = '-';
		return_string = num_to_string(n, str_len, return_string, 1);
	}
	else
		return_string = num_to_string(n, str_len, return_string, 0);
	return (return_string);
}
