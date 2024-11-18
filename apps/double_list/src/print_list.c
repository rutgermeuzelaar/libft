/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_list.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/17 21:34:13 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/11/18 09:47:32 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/double_list.h"

void	print_list(t_doubly_linked_list *list, void (*print_func)(void *))
{
	t_doubly_linked_node	*current;

	current = list->first;
	while (current != NULL)
	{
		print_func(current->data);
		current = current->next;
	}
}
