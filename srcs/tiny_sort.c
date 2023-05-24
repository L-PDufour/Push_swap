/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:56:42 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/24 14:46:32 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	tiny_sort(t_list **stack)
{
	int	highest_position;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	highest_position = find_highest_position(*stack);
	if ((*stack)->rank == highest_position)
		ra(stack);
	else if ((*stack)->next->rank == highest_position)
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank)
		sa(stack);
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
