/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:36:21 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/30 19:40:53 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Frees the memory allocated for the array and the stack, prints an error message,
and exits the program.
@param array The array to be freed.
@param stack A pointer to the stack (linked list) to be freed.
*/
void	free_error(char **array, t_list *stack)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	ft_lstfree(stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}

/*
Handles an error condition, frees the stack, and exits the program.
@param stack A pointer to the stack (linked list).
*/
void	error(t_list *stack)
{
	ft_lstfree(stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}
