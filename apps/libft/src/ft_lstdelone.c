/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/06/01 00:46:26 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/08/03 15:57:07 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/linked_list.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	del(lst);
}
