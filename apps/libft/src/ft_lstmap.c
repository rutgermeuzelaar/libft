/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 10:29:24 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:43:27 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

t_list	*ft_lstlist(const int size, void (*del)(void *))
{
	t_list	*first;
	t_list	*next;
	int		i;

	i = 0;
	first = ft_lstnew(NULL);
	if (first == NULL)
	{
		return (NULL);
	}
	while (i < size)
	{
		next = ft_lstnew(NULL);
		if (next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, next);
		i++;
	}
	return (first);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	const int	size = ft_lstsize(lst);
	int			i;
	t_list		*first_node;
	t_list		*new_list;

	i = 0;
	first_node = ft_lstlist(size, del);
	if (first_node == NULL)
	{
		return (NULL);
	}
	new_list = first_node;
	while (i < size)
	{
		new_list->content = f(lst->content);
		new_list = new_list->next;
		lst = lst->next;
		i++;
	}
	return (first_node);
}
