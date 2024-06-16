/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_back.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/01 00:40:20 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:43:06 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		ft_lstlast((*lst))->next = new;
	}
}
