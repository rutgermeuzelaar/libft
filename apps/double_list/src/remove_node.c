/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_node.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:19 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:59:56 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/double_list.h"

t_doubly_linked_node	*remove_node(t_doubly_linked_list *list, \
						t_doubly_linked_node *node, void (*func)(void *))
{
	t_doubly_linked_node	*next_node;

	next_node = node->next;
	cut_node(list, node);
	clear_node(node, func);
	return (next_node);
}
