/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_before.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:30:20 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:10 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

void	insert_before(t_doubly_linked_list *list, t_doubly_linked_node *node, \
		t_doubly_linked_node *new_node)
{
	new_node->next = node;
	new_node->prev = node->prev;
	if (node->prev != NULL)
	{
		node->prev->next = new_node;
	}
	else
	{
		list->first = new_node;
	}
	list->size++;
}
