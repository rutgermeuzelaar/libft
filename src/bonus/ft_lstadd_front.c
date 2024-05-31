/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 21:47:16 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/05/31 21:54:21 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = (*lst);
}
