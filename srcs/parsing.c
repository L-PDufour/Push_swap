/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/30 15:19:26 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Checks if a stack (linked list) is sorted in ascending order.
@param stack A pointer to the stack to be checked.
@return True if the stack is sorted, false otherwise.
*/
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

/*
Checks if a stack (linked list) contains any duplicate values.
@param stack A pointer to the stack to be checked.
@return True if duplicates are found, false otherwise.
*/
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

/*
Checks if all values in a stack (linked list) are within the range of int type.
@param stack A pointer to the stack to be checked.
@return True if all values are within the range, false otherwise.
*/
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

/*
Performs parsing checks on a stack, including checking for integer range,
duplicates, and sorted order.
@param stack A pointer to the stack to be parsed.
*/
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
