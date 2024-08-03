/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trie.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/26 14:49:49 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/07/26 17:54:38 by rmeuzela      ########   odam.nl         */
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

#endif