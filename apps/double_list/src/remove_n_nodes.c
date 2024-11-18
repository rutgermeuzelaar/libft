/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   remove_n_nodes.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:16 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:56:34 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

t_doubly_linked_node	*remove_n_nodes(t_doubly_linked_list *list, \
						t_doubly_linked_node *start, void (*func)(void *), \
						const int n)
{
	t_doubly_linked_node	*current;
	int						i;

	i = 0;
	current = start;
	while (current != NULL && i < n)
	{
		current = remove_node(list, current, func);
		i++;
	}
	if (current == NULL)
	{
		return (NULL);
	}
	return (current);
}
