/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:00:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:31:05 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Calculates the move cost for each node in the stack. It iterates through the
stack and assigns a move cost to each node based on its position relative to
the midpoint of the stack.
@param stack The stack for which to calculate the move cost.
*/
void	calculate_move_cost(t_list *stack)
{
	int	size;
	int	move_cost;

	size = ft_lstsize(stack);
	move_cost = 0;
	while (stack != NULL)
	{
		if (move_cost <= (size / 2))
			stack->cost = move_cost;
		if (move_cost > (size / 2))
			stack->cost = size - move_cost;
		stack = stack->next;
		move_cost++;
	}
}

/*
Finds the smallest chunk value in the given stack.
@param stack The stack to search.
@return The smallest chunk value found in the stack.
*/
int	find_small_chunk(t_list *stack)
{
	int	min;

	min = 1000;
	while (stack != NULL)
	{
		if (stack->chunk <= min)
			min = stack->chunk;
		stack = stack->next;
	}
	return (min);
}

/*
Finds the node with the smallest rank in the stack.
@param stack A pointer to the stack (linked list).
@return A pointer to the node with the smallest rank, or NULL if the stack
is empty.
*/
t_list	*find_smallest_rank(t_list **stack)
{
	t_list	*min_node;
	t_list	*current;

	if (*stack == NULL)
		return (NULL);
	min_node = *stack;
	current = (*stack)->next;
	while (current != NULL)
	{
		if (current->rank < min_node->rank)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}

/*
Push smallest node in stack B until 3 are left and use Tiny sort and
push to stack A.
@param stack_a The first stack.
@param stack_b The second stack.
*/
void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_node;

	while ((ft_lstsize(*stack_a)) > 3)
	{
		count_steps(*stack_a);
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->steps >= 0)
			while (smallest_node != (*stack_a))
				ra(stack_a);
		else
			while (smallest_node != (*stack_a))
				rra(stack_a);
	}
	tiny_sort(stack_a);
	while ((ft_lstsize(*stack_b)) != 0)
		pa(stack_b, stack_a);
}
