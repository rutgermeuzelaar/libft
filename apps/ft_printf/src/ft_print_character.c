/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_character.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/09 14:39:04 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:08:36 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_print_character(char character)
{
	ft_putchar_fd(character, 1);
	return (1);
}
