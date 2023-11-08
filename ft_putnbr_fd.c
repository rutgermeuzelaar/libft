/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/01 20:48:46 by rmeuzela      #+#    #+#                 */
/*   Updated: 2023/11/03 13:58:32 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	if (n < 0)
		ft_putchar_fd('-', fd);
	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		div = -div;
		mod = -mod;
	}
	n = div;
	if (div)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(mod + 48, fd);
}
