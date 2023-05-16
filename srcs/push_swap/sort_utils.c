/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:47 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 15:02:46 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_best_node(t_list **stack, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;

	update_index(*stack);
	first_node = find_first_node(stack, chunks);
	last_node = find_last_node(stack, chunks);
	if ((first_node->index) <= (ft_lstsize(*stack) - last_node->index))
	{
		while (first_node != (*stack))
			ra(stack);
	}
	else
	{
		while (last_node != (*stack))
			rra(stack);
	}
}

t_list	*find_first_node(t_list **stack, int chunks)
{
	t_list	*first_node;

	first_node = *stack;
	while (first_node != NULL)
	{
		if (first_node->rank <= chunks)
			break ;
		else
			first_node = first_node->next;
	}
	return (first_node);
}

t_list	*find_last_node(t_list **stack, int chunks)
{
	t_list	*last_node;

	last_node = *stack;
	while (last_node->next != NULL)
	{
		if (last_node->rank <= chunks)
			last_node = last_node;
		last_node = last_node->next;
	}
	return (last_node);
}

t_list	*find_highest_rank(t_list **stack)
{
	t_list	*max_node;
	t_list	*current;

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
int	update_index(t_list *stack)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	return (index);
}

t_list	*find_smallest_rank(t_list **stack_a)
{
	t_list	*min_node;
	t_list	*current;

	min_node = *stack_a;
	current = (*stack_a)->next;
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
