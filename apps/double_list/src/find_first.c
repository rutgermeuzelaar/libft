/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   find_first.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:33:50 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:59:37 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft/double_list.h"

t_doubly_linked_node	*find_first(t_doubly_linked_list *list, \
						bool (*find_func)(void *, void *), void *criteria)
{
	t_doubly_linked_node	*current;

	current = list->first;
	while (current != NULL)
	{
		if (find_func(current->data, criteria))
		{
			return (current);
		}
		current = current->next;
	}
	return (NULL);
}
