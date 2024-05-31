/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 12:45:40 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/01 00:55:03 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node != NULL)
	{
		new_node->content = malloc(sizeof(content));
		if (new_node->content != NULL)
		{
			new_node->content = content;
		}
	}
	new_node->next = NULL;
	return (new_node);
}
