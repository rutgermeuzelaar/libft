/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_n_list.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:33:39 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:56:11 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

t_doubly_linked_list	*copy_n_list(t_doubly_linked_node *start, const int n, \
						void *(copy_func)(void *), void(free_func)(void *))
{
	t_doubly_linked_list	*copied_list;
	t_doubly_linked_node	*current_copied;
	int						i;

	i = 0;
	copied_list = new_list(n, free_func);
	if (copied_list == NULL)
	{
		return (NULL);
	}
	current_copied = copied_list->first;
	while (start != NULL && current_copied != NULL)
	{
		current_copied->data = copy_func(start->data);
		if (current_copied->data == NULL)
		{
			clear_list(copied_list, free_func);
			return (NULL);
		}
		start = start->next;
		current_copied = current_copied->next;
		i++;
	}
	return (copied_list);
}
