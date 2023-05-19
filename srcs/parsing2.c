/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 20:36:21 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/19 14:41:14 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	error(t_list *stack)
{
	ft_lstfree(stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(0);
}

void	check_for_digit(char *str, char **array, t_list *stack)
{
	if (*str == 45)
		str++;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			free_error(array, stack);
		str++;
	}
}
