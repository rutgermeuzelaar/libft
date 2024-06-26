/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/02 10:23:59 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:43:23 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	const int	size = ft_lstsize(lst);
	int			i;

	i = 0;
	while (i < size)
	{
		f(lst->content);
		lst = lst->next;
		i++;
	}
}
