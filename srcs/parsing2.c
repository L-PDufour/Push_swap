/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:36:21 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/25 09:12:35 by ldufour          ###   ########.fr       */
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
	while (array[i])
	{
		free(array[i]);
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

/*
Checks if a string contains only digits.
@param str The string to check.
@param array An array of strings.
@param stack A pointer to the stack (linked list).
*/
void	check_for_digit(char *str, char **array, t_list *stack)
{
	if (*str == 45)
		str++;
	if (*str < '0' || *str > '9')
		free_error(array, stack);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			free_error(array, stack);
		str++;
	}
}
