/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/24 15:07:24 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
