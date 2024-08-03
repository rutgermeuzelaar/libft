/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 14:54:29 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 23:42:57 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/trie.h"

void	insert_next(t_trie *dest, t_trie *node)
{
	dest->next = node;	
}

t_trie	*new_trie_node(char symbol)
{
	t_trie *node;

	node = malloc(sizeof *node);
	if (node == NULL)
	{
		return (NULL);
	}
	node->c = symbol;
	node->child = NULL;
	node->next = NULL;
	return (node);
}

// app apple

t_trie	*traverse_childs(t_trie *root, char symbol)
{
	t_trie	*current;

	current = root;
	if (root == NULL)
	{
		return (NULL);
	}
	while (current->child != NULL)
	{
		if (current->c == symbol)
		{	
			return (current);
		}
		current = current->child;
	}
	return (NULL);	
}

t_trie *insert_substring(t_trie *root, char *string)
{
	t_trie	*node;

	node = root;
	node->child = new_trie_node(*string);
	node = node->child;
	string++;
	while (string && *string != '\0')
	{
		node->next = new_trie_node(*string);
		node = node->next;
		string++;
	}
	return (root);
}

t_trie	*new_trie(char *string)
{
	t_trie	*root;
	t_trie	*node;

	root = new_trie_node(*string);
	if (root == NULL)
	{
		return (NULL);
	}
	node = root;
	string++;
	while (*string != '\0')
	{
		insert_next(node, new_trie_node(*string));
		node = node->next;
		string++;
	}
	return (root);
}

t_trie	*insert_child(t_trie *parent, const char symbol)
{
	t_trie	*x_ptr;

	x_ptr = parent;
	if (parent == NULL)
	{
		return (NULL);
	}
	while (x_ptr->child != NULL)
	{
		x_ptr = x_ptr->child;
	}
	x_ptr->child = new_trie_node(symbol);
	if (x_ptr->child == NULL)
	{
		return (NULL);
	}
	return (x_ptr->child);	
}

t_trie	*insert_string(t_trie *root, char *string)
{
	t_trie	*y_ptr;
	t_trie	*x_ptr;

	y_ptr = root;
	x_ptr = NULL;
	if (root == NULL)
	{
		return (new_trie(string));
	}
	while (*string != '\0')
	{
		if (y_ptr->c == *string)
		{
			if (y_ptr->next)
				y_ptr = y_ptr->next;
		}
		if (y_ptr->next == NULL)
		{
			x_ptr = traverse_childs(y_ptr, *string);
			if (x_ptr)
				y_ptr = x_ptr;
			else
			{
				insert_substring(y_ptr, string);
				break ;
			}
		}
		string++;
	}
	return (root);
}
