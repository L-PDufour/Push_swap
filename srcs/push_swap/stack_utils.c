/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:59 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/15 13:05:21 by ldufour          ###   ########.fr       */
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

void	check_for_errors(t_list *stack)
{
	while (stack->next != NULL)
	{
		if (stack->content == stack->next->content)
		{
			ft_lstclear(&stack);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
		}
		if (stack->content > INT_MAX || stack->content < INT_MIN)
		{
			ft_lstclear(&stack);
			ft_putstr_fd("Error\n", STDERR_FILENO);
			exit(1);
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

	new_node = NULL;
	data = 0;
	i = 1;
	argv_copy = NULL;
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

void chunks_init(t_list **stack)
{
	
}
