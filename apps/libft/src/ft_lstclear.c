/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 09:24:18 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:56:50 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft/linked_list.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	const int	size = ft_lstsize((*lst));
	int			i;
	t_list		*current_node;
	t_list		*next_node;

	i = 0;
	current_node = (*lst);
	while (i < size)
	{
		next_node = current_node->next;
		ft_lstdelone(current_node, del);
		current_node = next_node;
		i++;
	}
	*lst = NULL;
}
