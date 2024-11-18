/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_list_end.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:03 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 16:36:39 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <assert.h>
#include "libft/double_list.h"

void	insert_list_end(t_doubly_linked_list *list, \
						t_doubly_linked_node *new_node)
{
	if (list->last == NULL)
	{
		assert(list->size == 0);
		list->first = new_node;
		list->last = new_node;
		list->size = 1;
	}
	else
	{
		insert_after(list, list->last, new_node);
	}
}
