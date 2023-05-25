/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:47 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:47:59 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Finds the node with the highest rank in the stack.
@param stack A pointer to the stack (linked list).
@return A pointer to the node with the highest rank, or NULL if the stack
is empty.
*/
t_list	*find_highest_rank(t_list **stack)
{
	t_list	*max_node;
	t_list	*current;

	if (*stack == NULL)
		return (NULL);
	max_node = *stack;
	current = (*stack)->next;
	while (current != NULL)
	{
		if (current->rank > max_node->rank)
		{
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}

/*
Counts the steps for each node in the stack based on its position.
@param stack A pointer to the stack (linked list).
 */
void	count_steps(t_list *stack)
{
	int	steps;
	int	size;

	size = ft_lstsize(stack);
	steps = 0;
	while (stack != NULL)
	{
		if (steps <= (size / 2))
			stack->steps = steps;
		else
			stack->steps = steps - size;
		stack = stack->next;
		steps++;
	}
}
