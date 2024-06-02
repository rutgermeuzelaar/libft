/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 22:06:22 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/02 18:40:38 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

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
