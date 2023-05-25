/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:57:15 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:21:47 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Performs a rotate operation on the specified stack.
Moves the top element to the bottom of the stack.
@param stack The stack on which the rotate operation is performed.
*/
void	move_rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_list **stack)
{
	move_rotate(stack);
	printf("ra\n");
}

void	rb(t_list **stack)
{
	move_rotate(stack);
	printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	move_rotate(stack_a);
	move_rotate(stack_b);
	printf("rr\n");
}
