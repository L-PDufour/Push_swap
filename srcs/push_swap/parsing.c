/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 14:03:03 by ldufour          ###   ########.fr       */
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
		while (tmp->next != NULL)
		{
			if (stack->content == tmp->content)
				error(stack);
			tmp = tmp->next;
		}
		stack = stack->next;
	}
}

t_list	*stack_init(int argc, char **argv, t_list *stack)
{
	int		i;
	int		j;
	long	data;
	char	**argv_copy;
	t_list	*new_node;

	data = 0;
	i = 1;
	while (i < argc)
	{
		argv_copy = ft_split(argv[i], ' ');
		j = 0;
		while (argv_copy[j])
		{
			data = ft_atoi(argv_copy[j]);
			free(argv_copy[j]);
			new_node = ft_lstnew(data);
			ft_lstadd_back(&stack, new_node);
			j++;
		}
		free(argv_copy);
		argv_copy = NULL;
		i++;
	}
	return (stack);
}


void	check_if_int(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content > INT_MAX || stack->content < INT_MIN)
			error(stack);
		stack = stack->next;
	}
}

void	parsing(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	// if (check_if_sorted)
	check_if_int(tmp);
	tmp = stack;
	check_for_duplicates(tmp);
}
