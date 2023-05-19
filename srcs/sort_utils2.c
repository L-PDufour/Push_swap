/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:54:06 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/19 15:32:56 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	better_sa(t_list **stack_a)
{
	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (((*stack_a)->chunk == (*stack_a)->next->chunk)
		&& ((*stack_a)->rank > (*stack_a)->next->rank))
		sa(stack_a);
	// if ((*stack_a)->rank < (*stack_a)->next->rank)
	// 	sa(stack_a);
}

void	find_best_node(t_list **stack_a, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;

	calculate_move_cost(*stack_a);
	first_node = find_first_node(stack_a, chunks);
	last_node = find_last_node(stack_a, chunks);
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
