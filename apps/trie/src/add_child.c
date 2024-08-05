/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_child.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:46:29 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/05 14:47:43 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/linked_list.h"
#include "libft/trie.h"

t_trie	*add_child(t_trie *parent, char symbol)
{
	t_trie	*trie_node;
	t_list	*list_node;

	trie_node = new_trie_node(symbol);
	if (trie_node == NULL)
	{
		return (NULL);
	}
	list_node = ft_lstnew(trie_node);
	if (list_node == NULL)
	{
		ft_lstdelone(list_node, free);
		return (NULL);
	}
	if (parent->children == NULL)
	{
		parent->children = list_node;
		return (parent->children->content);		
	}
	ft_lstadd_back(&parent->children, list_node);
	return (list_node->content);
}
