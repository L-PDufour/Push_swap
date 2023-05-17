/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:47 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/17 16:49:57 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	find_best_node(t_list **stack_a, t_list **stack_b, int chunks)
{
	t_list	*first_node;
	t_list	*last_node;
	t_list	*max_node;
	t_list	*bottom;

	max_node = find_highest_rank(stack_b);
	update_index(*stack_a);
	first_node = find_first_node(stack_a, chunks);
	last_node = find_last_node(stack_a, chunks);
	if ((first_node->index) <= (ft_lstsize(*stack_a) - last_node->index))
		while (*stack_a != first_node)
			ra(stack_a);
	else
		while (*stack_a != last_node)
			rra(stack_a);
}

t_list	*find_first_node(t_list **stack, int chunks)
{
	t_list	*first_node;
	t_list	*current_node;

	first_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank <= chunks)
		{
			first_node = current_node;
			break ;
		}
		current_node = current_node->next;
	}
	return (first_node);
}

t_list	*find_last_node(t_list **stack, int chunks)
{
	t_list	*current_node;
	t_list	*last_node;

	last_node = NULL;
	current_node = *stack;
	while (current_node != NULL)
	{
		if (current_node->rank <= chunks)
			last_node = current_node;
		current_node = current_node->next;
	}
	return (last_node);
}

t_list	*find_highest_rank(t_list **stack)
{
	t_list	*max_node;
	t_list	*current;

	if (*stack == NULL)
		return (NULL);
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

int	update_index(t_list *stack)
{
	t_list	*tmp;
	int		index;

	index = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->index = index;
		index++;
		tmp = tmp->next;
	}
	return (index);
}

t_list	*find_smallest_rank(t_list **stack_a)
{
	t_list	*min_node;
	t_list	*current;

	min_node = *stack_a;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->rank < min_node->rank)
		{
			min_node = current;
		}
		current = current->next;
	}
	return (min_node);
}
void	count_steps_a(t_list *stack_a)
{
	int	steps;
	int	size;

	size = ft_lstsize(stack_a);
	steps = 0;
	while (stack_a != NULL)
	{
		if (steps <= (size / 2))
			stack_a->steps_a = steps;
		else
			stack_a->steps_a = steps - size;
		stack_a = stack_a->next;
		steps++;
	}
}

void	count_steps_b(t_list *stack_b)
{
	int	steps;
	int	size;

	size = ft_lstsize(stack_b);
	steps = 0;
	while (stack_b != NULL)
	{
		if (steps <= (size / 2))
			stack_b->steps_b = steps;
		else
			stack_b->steps_b = steps - size;
		stack_b = stack_b->next;
		steps++;
	}
}
void	chunk_init(t_list **stack_a)
{
	t_list	*head;
	int		nbr_of_chunks;
	int		chunk_size;
	int		total_size;
	int		chunks_count;
	int		j;

	j = 1;
	total_size = ft_lstsize(*stack_a);
	nbr_of_chunks = (int)((float)total_size * 0.02 + 3);
	chunk_size = (int)((float)total_size / nbr_of_chunks);
	while (j <= nbr_of_chunks)
	{
		head = *stack_a;
		chunks_count = total_size * j / nbr_of_chunks;
		while (head->next != NULL)
		{
			if (head->rank > chunks_count)
				head->chunk = j;
			head = head->next;
		}
		j++;
	}
}
void	print_stack(t_list *stack)
{
	while (stack != NULL)
	{
		printf("%i\n", stack->chunk);
		// printf("%i\n", stack->index);
		stack = stack->next;
	}
}
