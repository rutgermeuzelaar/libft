/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_trie_node.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:49:24 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 13:42:17 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/trie.h"

t_trie	*new_trie_node(char symbol)
{
	t_trie	*node;

	node = malloc(sizeof(t_trie));
	if (node == NULL)
	{
		return (NULL);
	}
	node->children = NULL;
	node->c = symbol;
	node->complete = false;
	return (node);
}
