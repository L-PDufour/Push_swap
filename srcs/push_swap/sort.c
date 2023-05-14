/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:54 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/14 14:55:51 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		index;
	int		proximity;
	t_list	*smallest_node;

	proximity = ((ft_lstsize(*stack_a)) / 4);
	while ((ft_lstsize(*stack_a)) > proximity)
	{
		index = give_index(*stack_a);
		smallest_node = find_best_rank(stack_a, proximity);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node->index < proximity)
			ra(stack_a);
		else
			rra(stack_a);
		proximity++;
	}
	while ((ft_lstsize(*stack_b)) != 0)
	{
		pa(stack_b, stack_a);
	}
}

t_list	*find_best_rank(t_list **stack_a, int key_nbr)
{
	t_list	*min_node;
	t_list	*current;

	min_node = *stack_a;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->rank <= key_nbr)
		{
			min_node = current;
			break ;
		}
		current = current->next;
	}
	return (min_node);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	int		index;
	int		proximity;
	t_list	*smallest_node;

	index = give_index(*stack_a);
	proximity = ((ft_lstsize(*stack_a)) / 2);
	while ((ft_lstsize(*stack_a)) > 3)
	{
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->index < proximity)
			ra(stack_a);
		else
			rra(stack_a);
	}
	tiny_sort(stack_a);
	while ((ft_lstsize(*stack_b)) != 0)
	{
		pa(stack_b, stack_a);
	}
}
/* Stuck on ra. Je traverse la liste.*/
