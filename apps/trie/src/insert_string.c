/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_string.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:52:53 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/05 14:53:06 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/trie.h"

t_trie	*insert_string(t_trie *root, char *string)
{
	t_trie	*current;
	t_trie	*child;

	current = root;	
	while (*string != '\0')
	{
		child = in_children(current, *string);
		if (child == NULL)
		{
			current = add_child(current, *string);
		}
		else
		{
			current = child;
		}
		string++;
	}
	current->complete = true;
	return (root);	
}

