/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   insert_list_start.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:07 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:20 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

void	insert_list_start(t_doubly_linked_list *list, \
		t_doubly_linked_node *new_node)
{
	if (list->first == NULL)
	{
		list->first = new_node;
		list->last = new_node;
	}
	else
	{
		insert_before(list, list->first, new_node);
	}
}
