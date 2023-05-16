/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:44 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 11:26:27 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (1);
	stack_a = stack_init(argc, argv, stack_a);
	check_for_errors(stack_a);
	if (check_if_sorted(stack_a) == 0)
	{
		ft_lstclear(&stack_a);
		return (1);
	}
	rank_final(&stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		tiny_sort(&stack_a);
	else if (size > 3 && size <= 10)
		medium_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
