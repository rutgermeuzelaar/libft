/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/31 22:01:49 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/06/16 20:43:31 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	if (lst == NULL)
	{
		return (0);
	}
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}
