/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:59:13 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 15:18:36 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_node;

	while ((ft_lstsize(*stack_a)) > 3)
	{
		update_index(*stack_a);
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->index < ft_lstsize(*stack_a) / 2)
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
	int		chunks;
	int		total_size;
	int		i;
	int		j;
	t_list	*smallest_node;

	j = 1;
	total_size = ft_lstsize(*stack_a);
	chunks = ((ft_lstsize(*stack_a)) * 0.015 + 3.5);
	while ((ft_lstsize(*stack_a)) > 0)
	{
		i = 0;
		while ((i < chunks))
		{
			if ((*stack_a)->rank <= total_size * j / 5)
			{
				pb(stack_a, stack_b);
				i++;
			}
			else if ((*stack_a)->next->rank <= total_size * j / 5)
				sa(stack_a);
			else
				find_best_node(stack_a, total_size * j / 5);
		}
		j++;
	}
	while (ft_lstsize(*stack_b) != 0)
	{
		update_index(*stack_b);
		smallest_node = find_highest_rank(stack_b);
		if (smallest_node == (*stack_b))
			pa(stack_b, stack_a);
		else if (smallest_node == (*stack_b)->next)
			sb(stack_b);
		else if (smallest_node->index < (ft_lstsize(*stack_b) / 2))
			rb(stack_b);
		else
			rrb(stack_b);
	}
}
