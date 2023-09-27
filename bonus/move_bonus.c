/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour </var/spool/mail/ldufour>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:32:14 by ldufour           #+#    #+#             */
/*   Updated: 2023/09/27 14:32:14 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_reverse_rotate(t_list **stack_a, t_list **stack_b, char *line,
		int len)
{
	if (ft_strncmp("rra", line, len) == 0)
		move_reverse_rotate(stack_a);
	else if (ft_strncmp("rrb", line, len) == 0)
		move_reverse_rotate(stack_b);
	else if (ft_strncmp("rrr", line, len) == 0)
	{
		move_reverse_rotate(stack_a);
		move_reverse_rotate(stack_b);
	}
}

void	do_rotate(t_list **stack_a, t_list **stack_b, char *line, int len)
{
	if (ft_strncmp("ra", line, len) == 0)
		move_rotate(stack_a);
	else if (ft_strncmp("rb", line, len) == 0)
		move_rotate(stack_b);
	else if (ft_strncmp("rr", line, len) == 0)
	{
		move_rotate(stack_a);
		move_rotate(stack_b);
	}
}

void	do_swap(t_list **stack_a, t_list **stack_b, char *line, int len)
{
	if (ft_strncmp("sa", line, len) == 0)
		move_swap(stack_a);
	else if (ft_strncmp("sb", line, len) == 0)
		move_swap(stack_b);
	else if (ft_strncmp("ss", line, len) == 0)
	{
		move_swap(stack_a);
		move_swap(stack_b);
	}
}
