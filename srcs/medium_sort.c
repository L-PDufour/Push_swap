/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:00:36 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/20 21:38:33 by ldufour          ###   ########.fr       */
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
	// t_list	*smallest_node;

	count_steps(*stack_b);
	biggest_node = find_highest_rank(stack_b);
	// smallest_node = find_smallest_rank(stack_a);
	// if (smallest_node->rank < biggest_node->rank)
	// 	while ((*stack_a) != smallest_node)
	// 		rra(stack_a);
	if (biggest_node == (*stack_b))
		pa(stack_b, stack_a);
	else if (biggest_node->steps >= 0)
	{
		// if (((*stack_b)->rank > (*stack_a)->rank))
		// {
		// 	pa(stack_b, stack_a);
		// 	ra(stack_a);
		// }
		rb(stack_b);
	}
	else
	{
		// if (((*stack_b)->rank > (*stack_a)->rank)
		// 	&& (((*stack_b)->rank < (ft_lstlast(*stack_a)->rank))
		// 	|| ft_lstlast(*stack_a)->rank == ft_lstsize(*stack_a)))
		// {
		// 	pa(stack_b, stack_a);
		// 	ra(stack_a);
		// }
		rrb(stack_b);
	}
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

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	int	chunks;

	// if (stack_a == NULL || stack_b == NULL)
	// 	return ;
	while (ft_lstsize(*stack_a) > 0)
	{
		chunks = find_small_chunk(*stack_a) + 1;
		// better_sa(stack_a);
		find_best_node(stack_a, chunks);
		pb(stack_a, stack_b);
		if ((*stack_b)->next != NULL
			&& ((*stack_b)->chunk < (*stack_b)->next->chunk))
			rb(stack_b);
		// big_sort(stack_a, stack_b);
	}
	// tiny_sort(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		big_sort_stack_b(stack_a, stack_b);
	/*
		compare rank entre le A et le B
			si le plus petit est dans le B
				sort_b
			si dans le a
			rra until found
		if (stack_b->rank > stack_a->rank
			pa
			if (!bottom stack_a->rank == max rank
			stack_b->rank > stack_a->rank )
		*/
}
