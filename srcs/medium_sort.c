/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:00:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/21 13:42:00 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	calculate_move_cost(t_list *stack)
{
	int	size;
	int	move_cost;

	size = ft_lstsize(stack);
	move_cost = 0;
	while (stack != NULL)
	{
		if (move_cost <= (size / 2))
			stack->cost = move_cost;
		if (move_cost > (size / 2))
			stack->cost = size - move_cost;
		stack = stack->next;
		move_cost++;
	}
}

int	find_small_chunk(t_list *stack)
{
	int	min;

	min = 1000;
	while (stack != NULL)
	{
		if (stack->chunk <= min)
			min = stack->chunk;
		stack = stack->next;
	}
	return (min);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	big_sort_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node->steps >= 0)
		rb(stack_b);
	else
		rrb(stack_b);
}

void	medium_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*smallest_node;

	while ((ft_lstsize(*stack_a)) > 3)
	{
		count_steps(*stack_a);
		smallest_node = find_smallest_rank(stack_a);
		if (smallest_node == (*stack_a))
			pb(stack_a, stack_b);
		else if (smallest_node == (*stack_a)->next)
			sa(stack_a);
		else if (smallest_node->steps >= 0)
			ra(stack_a);
		else
			rra(stack_a);
	}
	tiny_sort(stack_a);
	while ((ft_lstsize(*stack_b)) != 0)
		pa(stack_b, stack_a);
}

void	better_sa(t_list **stack_a)
{
	if (stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	if (((*stack_a)->chunk == (*stack_a)->next->chunk)
		&& ((*stack_a)->rank < (*stack_a)->next->rank))
		sa(stack_a);
	// if ((*stack_a)->rank < (*stack_a)->next->rank)
	// 	sa(stack_a);
}

void	push_biggest_rank_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*biggest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node->steps >= 0)
		rb(stack_b);
	else
		rrb(stack_b);
}

t_list	*find_first_node_stack_b(t_list **stack, int best_rank)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank >= best_rank)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

t_list	*find_last_node_stack_b(t_list **stack, int best_rank)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->chunk >= best_rank)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}

t_list	*compare_cost(t_list **stack_b, int best_rank)
{
	t_list	*first_node;
	t_list	*last_node;

	first_node = find_first_node_stack_b(stack_b, best_rank);
	last_node = find_last_node_stack_b(stack_b, best_rank);
	if (first_node->cost <= last_node->cost)
		return (first_node);
	else
		return (last_node);
}

void	find_best_node_stack_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*highest_rank;
	t_list	*best_node;
	int		best_rank;

	calculate_move_cost(*stack_b);
	count_steps(*stack_b);
	highest_rank = find_highest_rank(stack_b);
	best_rank = ft_lstlast(*stack_a)->rank;
	best_node = compare_cost(stack_b, best_rank);
	if (highest_rank->cost >= best_node->cost)
		highest_rank = best_node;
	while (highest_rank != (*stack_b))
	{
		if (highest_rank->steps >= 0)
			rb(stack_b);
		else
			rrb(stack_b);
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int		chunks;
	t_list	*highest_rank;
	int		i;

	while (ft_lstsize(*stack_a) > 0)
	{
		chunks = find_small_chunk(*stack_a) + 1;
		find_best_node(stack_a, chunks);
		pb(stack_a, stack_b);
		if ((*stack_b)->next != NULL
			&& ((*stack_b)->chunk < (*stack_b)->next->chunk))
			rb(stack_b);
	}
	while (ft_lstsize(*stack_a) == 0)
		push_biggest_rank_stack_b(stack_a, stack_b);
	highest_rank = ft_lstlast(*stack_a);
	pa(stack_b, stack_a);
	i = 0;
	while (i < 5)
	{
		if ((*stack_b)->rank == (*stack_a)->rank - 1)
			pa(stack_b, stack_a);
		else if (ft_lstlast(*stack_a) == highest_rank)
		{
			pa(stack_b, stack_a);
			ra(stack_a);
		}
		else if ((*stack_a)->rank != (*stack_a)->next->rank - 1)
			ra(stack_a);
		else if ((*stack_b)->rank == (*stack_a)->rank - 1)
			pa(stack_a, stack_b);
		if (ft_lstlast(*stack_a)->rank == (*stack_a)->rank - 1)
			rra(stack_a);
		else if ((*stack_b)->rank != (*stack_a)->rank - 1
				&& (*stack_b)->rank > ft_lstlast(*stack_a)->rank)
		{
			pa(stack_a, stack_b);
			ra(stack_a);
		}
		// else if ((*stack_b)->rank != (*stack_a)->rank - 1
		// 		&& (*stack_b)->rank < ft_lstlast(*stack_a)->rank)
		// 	find_best_node_stack_b(stack_a, stack_b);
		// big_sort_stack_b(stack_a, stack_b);
		i++;
	}
	// big_sort_stack_b(stack_a, stack_b);
}
