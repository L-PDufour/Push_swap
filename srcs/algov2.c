/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algov2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 11:04:29 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/20 18:44:26 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*

	while stack_a not empty
	Give steps to my stack_a
	Find my best node
		Compare cost of first chunk found vs ast value (RA vs RRA)
			Peek in stack_b
				DO RR or RRR until biggest rank == stack_b head
					PB if stack_B < rank closer to next do SB or closer to last do RRB

	*/

// 	void	find_best_node_v2(t_list **stack_a, t_list **stack_b, int chunks)
// {
// 	t_list	*first_node;
// 	t_list	*last_node;
// 	t_list	*highest_rank_in_b;

// 	calculate_move_cost(*stack_a);
// 	first_node = find_first_node(stack_a, chunks);
// 	last_node = find_last_node(stack_a, chunks);
// 	if (first_node->cost <= last_node->cost)
// 		while (*stack_a != first_node)
// 		{
// 			highest_rank_in_b = find_highest_rank(stack_b);
// 			if (highest_rank_in_b != (*stack_b))
// 				rr(stack_a, stack_b);
// 			else
// 				ra(stack_a);
// 		}
// 	else
// 		while (*stack_a != last_node)
// 		{
// 			highest_rank_in_b = find_highest_rank(stack_b);
// 			if (highest_rank_in_b != (*stack_b))
// 				rrr(stack_a, stack_b);
// 			else
// 				rra(stack_a);
// 		}
// }

t_list	*find_first_node_v2(t_list **stack, int chunks)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank <= chunks)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

t_list	*find_last_node_v2(t_list **stack, int chunks)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank <= chunks)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}

void	find_best_node_v2(t_list **stack_a, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;

	calculate_move_cost(*stack_a);
	first_node = find_first_node_v2(stack_a, chunks);
	last_node = find_last_node_v2(stack_a, chunks);
	if (first_node->cost <= last_node->cost)
		while (*stack_a != first_node)
		{
			// better_sa(stack_a);
			ra(stack_a);
		}
	else
		while (*stack_a != last_node)
		{
			// better_sa(stack_a);
			rra(stack_a);
		}
}

void	better_big_sort(t_list **stack_a, t_list **stack_b)
{
	int		chunks;
	int		len;
	int		i;
	t_list	*smallest_node;
	int		ratio;

	ratio = 14 * 2;
	len = ft_lstsize(*stack_a);
	i = 1;
	while (i < len)
	{
		count_steps(*stack_a);
		smallest_node = find_smallest_rank(stack_a);
		chunks = smallest_node->rank + ratio;
		find_best_node_v2(stack_a, chunks);
		pb(stack_a, stack_b);
		if ((*stack_b)->rank > (chunks - ratio))
			rb(stack_b);
		i++;
		// if ((*stack_b)->rank < (*stack_b)->next->rank)
		// 	sb(stack_b);
		// else
		// 	rrb(stack_b);
	}
	while (ft_lstsize(*stack_b) != 0)
		big_sort_stack_b(stack_a, stack_b);
}
