/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 14:49:49 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 20:10:40 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H

typedef struct s_trie
{
	char			c;
	struct s_trie	*next;
	struct s_trie	*child;
}	t_trie;

void	insert_next(t_trie *dest, t_trie *node);
t_trie	*new_trie_node(char symbol);
t_trie	*traverse_childs(t_trie *root, char symbol);
t_trie	*new_trie(char *string);
t_trie	*insert_string(t_trie *root, char *string);
#endif