/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:00:33 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/31 20:41:19 by ldufour          ###   ########.fr       */
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
Checks and adjusts the bottom elements of stack_a if necessary.
@param stack_a The stack to check.
*/
void	check_bottom(t_list **stack_a)
{
	while (ft_lstlast(*stack_a)->rank == (*stack_a)->rank - 1)
		rra(stack_a);
}

/*
Pushes the node with the biggest rank from stack_b to stack_a.
@param stack_a   The stack A.
@param stack_b   The stack B.
*/
void	push_biggest_rank_stack_b(t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node->steps >= 0)
		while (biggest_node != (*stack_b))
			rb(stack_b);
	else
		while (biggest_node != (*stack_b))
			rrb(stack_b);
}

/*
Finds the first node with a rank greater than or equal to the given best_rank
in stack_b.
@param stack     The stack B.
@param best_rank The best rank to compare against.
@return          The first node with a rank greater than or equal to
best_rank, or NULL if not found.
*/
t_list	*find_first_node_stack_b(t_list **stack, int bottom_rank)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank >= bottom_rank)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

/*
Finds the last node with a rank greater than or equal to the given best_rank
in stack_b.
@param stack     The stack B.
@param best_rank The best rank to compare against.
@return          The last node with a rank greater than or equal to
best_rank, or NULL if not found.
*/
t_list	*find_last_node_stack_b(t_list **stack, int bottom_rank)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank >= bottom_rank)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}
