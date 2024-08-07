/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 14:49:49 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/05 15:03:47 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIE_H
# define TRIE_H
# include <stdbool.h>
# include "libft/linked_list.h"

typedef struct s_trie
{
	char			c;
	bool			complete;
	t_list			*children;
}	t_trie;

t_trie	*new_trie_node(char symbol);
t_trie	*add_child(t_trie *parent, char symbol);
t_trie	*in_children(t_trie *parent, char symbol);
t_trie	*new_trie(void);
t_trie	*insert_string(t_trie *root, char *string);
bool	trie_search(t_trie *root, char *string);
void	trie_free(t_trie *root);
#endif