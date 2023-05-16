/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:54 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/15 20:15:52 by ldufour          ###   ########.fr       */
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
	int		chunks;
	t_list	*smallest_node;

	index = give_index(*stack_a);
	chunks = ((ft_lstsize(*stack_a)) / 2);
	while ((ft_lstsize(*stack_a)) > 3)
	{
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->index < chunks)
			ra(stack_a);
		else
			rra(stack_a);
	}
	tiny_sort(stack_a);
	while ((ft_lstsize(*stack_b)) != 0)
		pa(stack_b, stack_a);
}
/* Stuck on ra. Je traverse la liste.*/
void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		chunks;
	int		total_size;
	int		i;
	int		chunck;
	int		j;
	t_list	*smallest_node;
	int		half;

	j = 1;
	total_size = ft_lstsize(*stack_a);
	chunks = ((ft_lstsize(*stack_a)) / 4);

	while ((ft_lstsize(*stack_a)) > 3)
	{
		i = 0;
		while (i < chunks)
		{
			give_index(*stack_a);
			find_best_node(stack_a, total_size * j / 4);
			if ((*stack_a)->rank <= total_size * j / 4)
			{
				pb(stack_a, stack_b);
				i++;
			}
		}
		j++;
		// printf ("%i", chunks);
	}
	while (ft_lstsize(*stack_b) > 0)
	{
		half = ((ft_lstsize(*stack_b)) / 2);
		give_index(*stack_b);
		smallest_node = find_highest_rank(stack_b);
		if (smallest_node == (*stack_b))
			pa(stack_b, stack_a);
		else if (smallest_node == (*stack_b)->next)
			sb(stack_b);
		else if (smallest_node->index < half)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	find_best_node(t_list **stack, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = find_first_node(stack, chunks);
	last_node = find_last_node(stack, chunks);
	if ((first_node->index + 0) <= (ft_lstsize(*stack) - last_node->index))
	{
		while (first_node != (*stack))
			ra(stack);
	}
	else
	{
		while (last_node != (*stack))
			rra(stack);
	}
}

t_list	*find_first_node(t_list **stack, int chunks)
{
	t_list	*first_node;

	first_node = *stack;
	while (first_node != NULL)
	{
		if (first_node->rank <= chunks)
			break ;
		else
			first_node = first_node->next;
	}
	return (first_node);
}

t_list	*find_last_node(t_list **stack, int chunks)
{
	t_list	*last_node;

	last_node = *stack;
	while (last_node->next != NULL)
	{
		if (last_node->rank <= chunks)
			last_node = last_node;
		last_node = last_node->next;
	}
	return (last_node);
}

t_list	*find_highest_rank(t_list **stack)
{
	t_list	*max_node;
	t_list	*current;

	max_node = *stack;
	current = (*stack)->next;
	while (current != NULL)
	{
		if (current->rank > max_node->rank)
		{
			max_node = current;
		}
		current = current->next;
	}
	return (max_node);
}
