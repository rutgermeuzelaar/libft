/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clear_node.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:33:34 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:46:45 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

/**
 * This function frees an entire node.
 * @param node A pointer to a node that needs to be freed.
 * @param func This function should free the contents of the node data and the 
 * node data pointer itself.
 */
void	clear_node(t_doubly_linked_node	*node, void (*func)(void *))
{
	func(node->data);
	node->next = NULL;
	node->prev = NULL;
	free(node);
}
