/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_list.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:24:56 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:56:47 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"
#include "libft/libft.h"

t_doubly_linked_list	*new_list(const int size, void (*func)(void *))
{
	t_doubly_linked_list	*list;
	t_doubly_linked_node	*node;
	int						i;

	i = 0;
	list = ft_calloc(1, sizeof(t_doubly_linked_list));
	if (list == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		node = new_node(NULL);
		if (node == NULL)
		{
			clear_list(list, func);
			return (NULL);
		}
		if (i == 0)
			list->first = node;
		insert_list_end(list, node);
		i++;
	}
	list->size = size;
	return (list);
}
