/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_node.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:29:16 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:57 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"
#include "libft/libft.h"

t_doubly_linked_node	*new_node(void *data)
{
	t_doubly_linked_node	*node;

	node = ft_calloc(1, sizeof(t_doubly_linked_node));
	if (node == NULL)
	{
		return (NULL);
	}
	node->data = data;
	return (node);
}
