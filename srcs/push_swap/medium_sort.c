/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:59:13 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/17 15:13:47 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_node;

	while ((ft_lstsize(*stack_a)) > 3)
	{
		count_steps_a(*stack_a);
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->steps_a >=0)
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
	int	nbr_of_chunks;
	int	chunk_size;
	int	total_size;
	int	chunks_count;
	int	i;
	int	j;

	j = 1;
	total_size = ft_lstsize(*stack_a);
	nbr_of_chunks = (int)(((float)ft_lstsize(*stack_a)) * 0.02 + 3);
	chunk_size = (int)(((float)ft_lstsize(*stack_a)) / nbr_of_chunks);
	while ((ft_lstsize(*stack_a)) != 0)
	{
		i = 0;
		chunks_count = total_size * j / nbr_of_chunks;
		while (i < chunk_size && ft_lstsize(*stack_a) != 0)
		{
			if ((*stack_a)->rank <= chunks_count)
			{
				pb(stack_a, stack_b);
				i++;
			}
			else if ((*stack_a)->next->rank <= chunks_count)
				sa(stack_a);
			else
				find_best_node(stack_a, stack_b, chunks_count);
		}
		j++;
	}
	while (ft_lstsize(*stack_b) != 0)
		big_sort_stack_b(stack_a, stack_b);
}

void	big_sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps_b(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node == (*stack_b)->next)
		sb(stack_b);
	else if (biggest_node->steps_b >= 0)
		rb(stack_b);
	else
		rrb(stack_b);
}
