/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_list.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rmeuzela <rmeuzela@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/05 19:15:24 by rmeuzela      #+#    #+#                 */
/*   Updated: 2024/10/20 12:07:02 by rmeuzela      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOUBLE_LIST_H
# define DOUBLE_LIST_H
# include <stdbool.h>

typedef struct	s_doubly_linked_node
{
	struct s_doubly_linked_node	*next;
	struct s_doubly_linked_node	*prev;
	void						*data;
}	t_doubly_linked_node;

typedef struct	s_doubly_linked_list
{
	t_doubly_linked_node	*first;
	t_doubly_linked_node	*last;
	int						size;
}	t_doubly_linked_list;

void					init_list(t_doubly_linked_list *list);
t_doubly_linked_list	*new_list(const int size, void (* func)(void *));
void					init_node(t_doubly_linked_node *node);
t_doubly_linked_node	*new_node(void *data);
void					insert_before(t_doubly_linked_list *list, \
						t_doubly_linked_node *node, \
						t_doubly_linked_node *new_node);
void					insert_after(t_doubly_linked_list *list, \
						t_doubly_linked_node *node, \
						t_doubly_linked_node *new_node);
void					insert_list_start(t_doubly_linked_list *list, \
						t_doubly_linked_node *new_node);
void					insert_list_end(t_doubly_linked_list *list, \
						t_doubly_linked_node *new_node);

void					clear_node(t_doubly_linked_node	*node, \
						void (* func)(void *));
t_doubly_linked_node	*remove_node(t_doubly_linked_list *list, \
						t_doubly_linked_node *node, void (* func)(void *));
void					clear_list(t_doubly_linked_list *list, \
						void (*func)(void *));
t_doubly_linked_node	*remove_n_nodes(t_doubly_linked_list *list, \
						t_doubly_linked_node *start, void (* func)(void *), \
						const int n);

t_doubly_linked_node	*cut_node(t_doubly_linked_list *list, 
						t_doubly_linked_node *node);
t_doubly_linked_list	*copy_n_list(t_doubly_linked_node *start, const int n, \
						void *(copy_func)(void *), void(free_func)(void *));
void					print_list(t_doubly_linked_list *list, \
						void (*print_func)(void *));
t_doubly_linked_node	*find_first(
							t_doubly_linked_list *list, \
							bool (*find_func)(void *, void *),
							void *criteria
						);
#endif