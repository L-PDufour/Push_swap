/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 11:48:55 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Handles an error condition, frees the stack, and exits the program.
@param stack A pointer to the stack (linked list).
*/
void	error(t_list *stack)
{
	ft_lstfree(stack);
	printf("Error\n");
	exit(0);
}

/*
Checks if a stack (linked list) is sorted in ascending order.
@param stack A pointer to the stack to be checked.
@return True if the stack is sorted, false otherwise.
*/
bool	check_if_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	if (head == NULL || head->next == NULL)
		return (true);
	while (head && head->next != NULL)
	{
		if (head->content > head->next->content)
			return (false);
		head = head->next;
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
	if (check_if_sorted(&stack))
	{
		ft_lstfree(stack);
		exit(0);
	}
}
