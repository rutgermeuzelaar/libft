/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 09:24:18 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/02 12:23:37 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
		del(current_node);
		current_node = next_node;
		i++;
	}
	lst = NULL;
}
