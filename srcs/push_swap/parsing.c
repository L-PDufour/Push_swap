/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/18 20:42:11 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

bool	check_if_sorted(t_list *stack)
{
	if (stack == NULL || stack->next == NULL)
		return (true);
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	check_for_duplicates(t_list *stack)
{
	t_list	*current;
	t_list	*temp;

	current = stack;
	while (current != NULL)
	{
		temp = current->next;
		while (temp != NULL)
		{
			if (current->content == temp->content)
				return (true);
			temp = temp->next;
		}
		current = current->next;
	}
	return (false);
}

bool	check_if_int(t_list *stack)
{
	while (stack != NULL)
	{
		if (stack->content < INT_MIN || stack->content > INT_MAX)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	parsing(t_list *stack)
{
	if (!check_if_int(stack))
	{
		error(stack);
		exit(0);
	}
	if (check_for_duplicates(stack))
	{
		error(stack);
		exit(0);
	}
	if (check_if_sorted(stack))
	{
		ft_lstfree(stack);
		exit(0);
	}
}

void	chunk_init(t_list **stack_a)
{
	t_list	*head;
	int		nbr_of_chunks;
	int		chunk_size;
	int		chunks_count;
	int		j;

	j = 1;
	nbr_of_chunks = (int)((float)ft_lstsize(*stack_a) * 0.02 + 3);
	while (j <= nbr_of_chunks)
	{
		head = *stack_a;
		chunks_count = ft_lstsize(*stack_a) * j / nbr_of_chunks;
		while (head->next != NULL)
		{
			if (head->rank > chunks_count)
				head->chunk = j;
			head = head->next;
		}
		j++;
	}
}
