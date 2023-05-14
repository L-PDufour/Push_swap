/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:47 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/14 14:53:48 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rank_final(t_list **stack)
{
	t_list	*tmp;
	t_list	*checker;

	tmp = *stack;
	while (tmp)
	{
		tmp->rank = 0;
		checker = *stack;
		while (checker)
		{
			if (tmp->content > checker->content)
				tmp->rank += 1;
			checker = checker->next;
		}
		tmp = tmp->next;
	}
}

int	give_index(t_list *stack)
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

int	find_highest_position(t_list *stack)
{
	int	position;

	position = stack->rank;
	while (stack)
	{
		{
			if (stack->rank > position)
				position = stack->rank;
			stack = stack->next;
		}
	}
	return (position);
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
