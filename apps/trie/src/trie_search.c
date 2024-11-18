/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie_search.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:54:02 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 13:40:47 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft/trie.h"

bool	trie_search(t_trie *root, char *string)
{
	t_trie	*current;
	t_trie	*child;

	current = root;
	while (*string != '\0')
	{
		child = in_children(current, *string);
		if (child == NULL)
		{
			return (false);
		}
		current = child;
		string++;
	}
	if (current->complete)
	{
		return (true);
	}
	return (false);
}
