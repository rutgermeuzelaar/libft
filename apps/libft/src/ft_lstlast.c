/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 22:06:22 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:57:43 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/linked_list.h"

t_list	*ft_lstlast(t_list *lst)
{
	const int	size = ft_lstsize(lst);
	int			i;

	i = 0;
	while (i < (size - 1))
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
