/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:47 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/19 14:41:20 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
