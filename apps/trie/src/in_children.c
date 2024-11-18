/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   in_children.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:51:37 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 13:40:17 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/trie.h"

t_trie	*in_children(t_trie *parent, char symbol)
{
	t_list	*current;

	current = parent->children;
	if (current == NULL)
	{
		return (NULL);
	}
	while (current != NULL)
	{
		if (((t_trie *)current->content)->c == symbol)
		{
			return (current->content);
		}
		current = current->next;
	}
	return (NULL);
}
