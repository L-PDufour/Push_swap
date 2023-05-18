/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:54:06 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/18 10:58:07 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
