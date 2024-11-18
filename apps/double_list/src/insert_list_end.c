/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_list_end.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:03 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:15 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

void	insert_list_end(t_doubly_linked_list *list, \
						t_doubly_linked_node *new_node)
{
	if (list->last == NULL)
	{
		list->first = new_node;
		list->last = new_node;
	}
	else
	{
		insert_after(list, list->last, new_node);
	}
}
