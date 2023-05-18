/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:00:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/18 13:04:13 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

int find_small_chunk(t_list *stack)
{
	int min = 1000;

	while (stack != NULL)
	{
		if (stack->chunk <= min)
			min = stack->chunk;
		stack = stack->next;
	}

	return min;
}


void	big_sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node == (*stack_b)->next)
		sb(stack_b);
	else if (biggest_node->steps >= 0)
		rb(stack_b);
	else
		rrb(stack_b);
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
			ra(stack_a);
		else
			rra(stack_a);
	}
	tiny_sort(stack_a);
	while ((ft_lstsize(*stack_b)) != 0)
		pa(stack_b, stack_a);
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	len;
	int	i;
	int	chunks;

    if (stack_a == NULL || stack_b == NULL)
        return;
	len = ft_lstsize(*stack_a);
	i = 0;
	while (i < len)
	{
		chunks = find_small_chunk(*stack_a);
		if ((*stack_a)->chunk <= chunks)
		{
			pb(stack_a, stack_b);
			i++;
		}
		else if ((*stack_a)->next != NULL && (*stack_a)->next->chunk <= chunks)
			sa(stack_a);
		else
			find_best_node(stack_a, stack_b, chunks);
	}
	while (ft_lstsize(*stack_b) != 0)
		big_sort_stack_b(stack_a, stack_b);
}
