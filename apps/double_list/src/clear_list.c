/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:33:27 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:46:34 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

/**
 * Frees memory with user supplied function.
 * list - The list to free.
 * func - The function that frees the data pointer of each node.
 */
void	clear_list(t_doubly_linked_list *list, void (*func)(void *))
{
	if (list == NULL)
	{
		return ;
	}
	while (list->size != 0)
	{
		remove_node(list, list->first, func);
	}
	free(list);
}
