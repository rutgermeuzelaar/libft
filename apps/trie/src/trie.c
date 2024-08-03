/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 14:54:29 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 16:39:29 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/trie.h"

void	insert_next(t_trie *dest, t_trie *node)
{
	dest->next = node;	
}

t_trie	*new_node(char symbol)
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

t_trie	*traverse_childs(t_trie *root, char *string)
{
	t_trie	*current;

	current = root;
	while (current->child != NULL)
	{
		if (current->c == *string)
		{	
			return (current);
		}
		current = current->child;
	}
	return (NULL);	
}

t_trie	*new_trie(char *string)
{
	t_trie	*root;
	t_trie	*node;

	root = new_node(*string);
	if (root == NULL)
	{
		return (NULL);
	}
	node = root;
	string++;
	while (*string != '\0')
	{
		insert_next(node, new_node(*string));
		node = node->next;
		string++;
	}
	return (root);
}

t_trie	*insert_string(t_trie *root, char *string)
{
	t_trie	*y_ptr;
	t_trie	*x_ptr;

	y_ptr = root;
	if (root == NULL)
	{
		return (new_trie(string));
	}
	while (*string != '\0')
	{
		x_ptr = traverse_childs(y_ptr, string);
		if (y_ptr->c == *string)
		{
			string++;
			if (*string == '\0')
			{
				break ;
			}
			if (y_ptr->next->c == *string)
			{
				y_ptr = y_ptr->next;
			}
		}
		else if (x_ptr != NULL)
		{
			string++;
			y_ptr = x_ptr;		
		}
		else
		{
			if (y_ptr->next == NULL)
			{
				y_ptr->next = new_node(*string);
				y_ptr = y_ptr->next;
			}
			else
			{
				while (y_ptr->child != NULL)
				{
					y_ptr = y_ptr->child;
				}
				y_ptr->child = new_node(*string);
				y_ptr = y_ptr->child;				
			}
			string++;
		}	
	}
	return (root);
}

int	main(void)
{
	t_trie *root = new_trie("baby");
	printf("%c\n", root->c);
	printf("%c\n", root->next->next->c);
	insert_string(root, "bank");
	printf("%c\n", root->next->c);
	printf("%c\n", root->next->child->c);
	return (0);
}