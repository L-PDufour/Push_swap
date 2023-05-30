/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:57:55 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/30 15:16:07 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Compares the move costs of the first and last nodes in stack_b and returns
the node with the lower cost.
@param stack_b   The stack to compare.
@param best_rank The rank to consider.
@return          The node with the lower cost.
*/
t_list	*compare_cost(t_list **stack_b, int bottom_rank)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = find_first_node_stack_b(stack_b, bottom_rank);
	last_node = find_last_node_stack_b(stack_b, bottom_rank);
	if (first_node != NULL && last_node != NULL
		&& first_node->cost <= last_node->cost)
		return (first_node);
	else
		return (last_node);
}

/**
Fills the bottom of stack_a under the biggest rank.
@param stack_a The first stack.
@param stack_b The second stack.
@param highest_rank The node with the highest rank in stack_a.*/
void	fill_bottom(t_list **stack_a, t_list **stack_b, t_list *highest_rank)
{
	while (ft_lstlast(*stack_a)->rank == highest_rank->rank)
	{
		pa(stack_b, stack_a);
		if (*stack_a && (*stack_a)->next
			&& (*stack_a)->rank != (*stack_a)->next->rank - 1)
			ra(stack_a);
		else
			break ;
	}
	while (*stack_b && (*stack_b)->rank == (*stack_a)->rank - 1)
	{
		pa(stack_b, stack_a);
		check_bottom(stack_a);
	}
	while ((*stack_b) && ((*stack_b)->rank > ft_lstlast(*stack_a)->rank
			|| ft_lstlast(*stack_a) == highest_rank))
	{
		pa(stack_b, stack_a);
		ra(stack_a);
	}
	find_best_node_stack_b(stack_a, stack_b);
	check_bottom(stack_a);
}

/*
Finds the best node in stack_b to move to stack_a based on their move costs
and ranks. The biggest one or the first one bigger than the bottom of a
@param stack_a The destination stack.
@param stack_b The source stack.
*/
void	find_best_node_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*highest_rank;
	t_list	*best_node;
	int		bottom_rank;

	calculate_move_cost(*stack_b);
	count_steps(*stack_b);
	highest_rank = find_highest_rank(stack_b);
	bottom_rank = ft_lstlast(*stack_a)->rank;
	best_node = compare_cost(stack_b, bottom_rank);
	if (highest_rank != NULL && best_node != NULL
		&& highest_rank->cost <= best_node->cost)
		highest_rank = best_node;
	if (highest_rank != NULL && highest_rank->steps >= 0)
		while (highest_rank != (*stack_b))
			rb(stack_b);
	else
		while (highest_rank != (*stack_b))
			rrb(stack_b);
}

/*
Finds the best node in stack A based on the given chunks and moves it to
stack B.
@param stack_a A pointer to stack A (linked list).
@param stack_b A pointer to stack B (linked list).
@param chunks  The maximum chunk value to consider.
*/
void	find_best_node(t_list **stack_a, t_list **stack_b, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;

	calculate_move_cost(*stack_a);
	first_node = find_first_node(stack_a, chunks);
	last_node = find_last_node(stack_a, chunks);
	if (first_node->cost <= last_node->cost)
		while (*stack_a != first_node)
			ra(stack_a);
	else
		while (*stack_a != last_node)
			rra(stack_a);
	pb(stack_a, stack_b);
}

/*
It iteratively selects the best node from stack_a and moves it to stack_b
while maintaining the order based on the chunks.
@param stack_a The first stack.
@param stack_b The second stack.
*/
void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		chunks;
	t_list	*highest_rank;

	while (ft_lstsize(*stack_a) > 0)
	{
		chunks = find_small_chunk(*stack_a) + 1;
		find_best_node(stack_a, stack_b, chunks);
		if ((*stack_b)->next != NULL
			&& ((*stack_b)->chunk < (*stack_b)->next->chunk))
			rb(stack_b);
	}
	push_biggest_rank_stack_b(stack_b);
	pa(stack_b, stack_a);
	highest_rank = ft_lstlast(*stack_a);
	while (ft_lstsize(*stack_b) > 0)
		fill_bottom(stack_a, stack_b, highest_rank);
}
