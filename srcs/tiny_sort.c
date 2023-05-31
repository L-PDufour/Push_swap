/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:56:42 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/30 19:35:26 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief Find the highest position (rank) in the stack.
This function traverses the stack and finds the highest position (rank) among
the elements. The position is determined by the rank field of each element.
@param stack The stack to search for the highest position.
@return The highest position (rank) in the stack.
*/
static int	find_highest_position(t_list *stack)
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

/*
@brief Perform a tiny sort on the stack.
This function performs a tiny sort on the stack, which is a specific set of
operations to sort a small number of elements. It utilizes the
find_highest_position function to determine the highest position (rank) in
the stack and applies the necessary stack operations to achieve the sorting.
@param stack The stack to perform the tiny sort on.
*/
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


