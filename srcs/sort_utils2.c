/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:54:06 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/26 09:02:22 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Finds and returns the first node in the stack with a chunk value less than or
equal to the given chunks.
@param stack  A pointer to the stack (linked list).
@param chunks The maximum chunk value to consider.
@return       The first node with chunk <= chunks, or NULL if no such
node is found.
*/
t_list	*find_first_node(t_list **stack, int chunks)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->chunk <= chunks)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

/*
Finds and returns the last node in the stack with a chunk value less than or
equal to the given chunks.
@param stack  A pointer to the stack (linked list).
@param chunks The maximum chunk value to consider.
@return       The last node with chunk <= chunks, or NULL if no such node
is found.
*/
t_list	*find_last_node(t_list **stack, int chunks)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->chunk <= chunks)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}
