/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:56:22 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/18 11:02:18 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_push(t_list **stack_from, t_list **stack_to)
{
	t_list	*tmp;

	if (*stack_from == NULL)
		return ;
	tmp = *stack_to;
	*stack_to = *stack_from;
	*stack_from = (*stack_from)->next;
	(*stack_to)->next = tmp;
}

void	pa(t_list **stack_b, t_list **stack_a)
{
	move_push(stack_b, stack_a);
	printf("pa\n");
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	move_push(stack_a, stack_b);
	printf("pb\n");
}
