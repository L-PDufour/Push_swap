/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 15:00:33 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/24 15:01:02 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_biggest_rank_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node->steps >= 0)
		while (biggest_node != (*stack_b))
			rb(stack_b);
	else
		while (biggest_node != (*stack_b))
			rrb(stack_b);
	pa(stack_b, stack_a);
}

t_list	*find_first_node_stack_b(t_list **stack, int best_rank)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank >= best_rank)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

t_list	*find_last_node_stack_b(t_list **stack, int best_rank)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank >= best_rank)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}
