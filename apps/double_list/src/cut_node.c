/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cut_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:33:42 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:57:33 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

t_doubly_linked_node	*cut_node(t_doubly_linked_list *list, \
						t_doubly_linked_node *node)
{
	if (node->prev == NULL)
	{
		list->first = node->next;
	}
	else
	{
		node->prev->next = node->next;
	}
	if (node->next == NULL)
	{
		list->last = node->prev;
	}
	else
	{
		node->next->prev = node->prev;
	}
	node->next = NULL;
	node->prev = NULL;
	list->size--;
	return (node);
}
