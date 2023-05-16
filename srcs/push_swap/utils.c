/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 14:54:01 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 13:12:32 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_error(char **array, t_list *stack)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	ft_lstclear(&stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
void	error(t_list *stack)
{
	ft_lstclear(&stack);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(1);
}
