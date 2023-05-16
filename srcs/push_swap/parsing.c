/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 14:55:57 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <limits.h>
#include <unistd.h>

int	check_if_sorted(t_list *stack)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		if (stack->content > stack->next->content)
			i++;
		stack = stack->next;
	}
	return (i);
}

void	check_for_duplicates(t_list *stack)
{
	t_list	*tmp;

	while (stack != NULL)
	{
		tmp = stack->next;
		while (tmp != NULL)
		{
			if (stack->content == tmp->content)
				error(stack);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

void check_if_int(t_list *stack)
{
	if (stack == NULL)
		return;

	while (stack != NULL)
	{
		if (!(stack->content <= INT_MAX && stack->content >= INT_MIN))
			error(stack);
		stack = stack->next;
	}
}

void	parsing(t_list *stack)
{
	check_if_int(stack);
	check_for_duplicates(stack);
	if (check_if_sorted(stack) == 1)
		exit (1);
}
