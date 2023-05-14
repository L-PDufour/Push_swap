/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:00:10 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/14 15:00:31 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	move_swap(t_list **stack)
{
	t_list	*node_a;
	t_list	*node_b;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	node_a = *stack;
	node_b = node_a->next;
	node_a->next = node_b->next;
	node_b->next = node_a;
	*stack = node_b;
}

void	sa(t_list **stack)
{
	move_swap(stack);
	printf("sa\n");
}

void	sb(t_list **stack)
{
	move_swap(stack);
	printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	move_swap(stack_a);
	move_swap(stack_b);
	printf("ss\n");
}
