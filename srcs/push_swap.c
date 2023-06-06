/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:53:44 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 13:53:15 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Frees the memory allocated for the array and the stack, prints an error message,
and exits the program.
@param array The array to be freed.
@param stack A pointer to the stack (linked list) to be freed.
*/
void	free_error(char *str, char **array, t_list *stack)
{
	free(str);
	free(array);
	ft_lstfree(stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	stack_a = stack_init(argc, argv, stack_a);
	parsing(stack_a);
	rank_final(&stack_a);
	chunk_init(&stack_a);
	size = ft_lstsize(stack_a);
	if (size == 2)
		sa(&stack_a);
	else if (size == 3)
		tiny_sort(&stack_a);
	else if (size > 3 && size <= 19)
		medium_sort(&stack_a, &stack_b);
	else
		big_sort(&stack_a, &stack_b);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	return (0);
}
