/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:44 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/20 18:45:59 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rank_final(t_list **stack)
{
	t_list	*tmp;
	t_list	*checker;

	tmp = *stack;
	while (tmp)
	{
		tmp->rank = 0;
		checker = *stack;
		while (checker)
		{
			if (tmp->content > checker->content)
				tmp->rank += 1;
			checker = checker->next;
		}
		tmp = tmp->next;
	}
}

long	ft_atol(const char *str, char **array, t_list *stack)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str || ft_strlen(str) == 0 || ft_strlen(str) > 10)
		free_error(array, stack);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 43)
		str++;
	else if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (result < INT_MIN || result > INT_MAX)
		free_error(array, stack);
	return (result * sign);
}

t_list	*stack_init(int argc, char **argv, t_list *stack)
{
	int		i;
	int		j;
	long	data;
	char	**argv_copy;
	t_list	*new_node;

	i = 0;
	while (++i < argc)
	{
		argv_copy = ft_split(argv[i], ' ');
		j = 0;
		while (argv_copy[j])
		{
			data = ft_atol(argv_copy[j], argv_copy, stack);
			check_for_digit(argv_copy[j], argv_copy, stack);
			free(argv_copy[j]);
			new_node = ft_lstnew(data);
			ft_lstadd_back(&stack, new_node);
			j++;
		}
		free(argv_copy);
		argv_copy = NULL;
	}
	return (stack);
}

// void	print_stack(t_list *stack)
// {
// 	while (stack != NULL)
// 	{
// 		printf("%i\n", stack->content);
// 		stack = stack->next;
// 	}
// }
// leaks dans ak 1 string still reachable ak chiffre

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	stack_a = stack_init(argc, argv, stack_a);
	parsing(stack_a);
	rank_final(&stack_a);
	chunk_init(&stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		tiny_sort(&stack_a);
	else if (size > 3 && size <= 10)
		medium_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
		// better_big_sort(&stack_a, &stack_b);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	return (0);
}
