/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_after.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:31:01 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:06 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

void	insert_after(t_doubly_linked_list *list, t_doubly_linked_node *node, \
		t_doubly_linked_node *new_node)
{
	new_node->prev = node;
	new_node->next = node->next;
	if (node->next == NULL)
	{
		list->last = new_node;
	}
	else
	{
		node->next->prev = new_node;
	}
	node->next = new_node;
	list->size++;
}
