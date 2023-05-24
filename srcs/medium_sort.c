/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:00:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/24 15:00:54 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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









