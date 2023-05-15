/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:54 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/15 10:43:22 by ldufour          ###   ########.fr       */
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

t_list	*find_best_rank(t_list **stack_a, int key_nbr)
{
	t_list	*current;

	current = *stack_a;
	while (current != NULL)
	{
		if (current->rank <= key_nbr)
			return (current);
		else
			current = current->next;
	}
	return (NULL);
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
void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp_b;
	t_list	*tmp_a;
	int		index;
	int		proximity;
	t_list	*smallest_node;
	int		total_size;
	int		i;

	i = 0;
	total_size = ft_lstsize(*stack_a);
	index = give_index(*stack_a);
	proximity = ((ft_lstsize(*stack_a)) / 4);
	while (proximity < total_size)
	{
		while (i < proximity)
		{
			tmp_a = (*stack_a);
			index = give_index(tmp_a);
			smallest_node = find_best_rank(&tmp_a, proximity);
			if (smallest_node == tmp_a)
			{
				pb(tmp_a, stack_b);
				i++;
			}
			else if (smallest_node->index < proximity)
				ra(tmp_a);
			else
				rra(tmp_a);
		}
		proximity++;
	}
	// while ((ft_lstsize(*stack_b)) != 0)
	// {
	// 	pa(stack_b, stack_a);
	// }
}

int	find_best_node(t_list *stack, int proximity)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = stack;
	last_node = stack;
	while (first_node != NULL)
	{
		if (first_node->rank <= proximity)
			break ;
		else
			first_node = first_node->next;
	}
	while (last_node->next != NULL)
	{
		if (last_node->rank <= proximity)
			last_node = last_node;
		last_node = last_node->next;
	}
	if ((first_node->index - 0) <= (last_node->index - ft_lstsize(stack)))
		return (1);
	else
		return (2);
}
