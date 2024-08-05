/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_trie.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/05 14:50:47 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/05 14:51:09 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/trie.h"

t_trie	*new_trie(void)
{
	t_trie	*root;
	
	root = new_trie_node('\0');
	if (root == NULL)
	{
		return (NULL);
	}
	root->complete = true;
	return (root);
}
