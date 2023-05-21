/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:36:55 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/20 16:19:52 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	chunk_init(t_list **stack_a)
{
	t_list	*head;
	int		nbr_of_chunks;
	int		chunks_count;
	int		j;

	j = 0;
	nbr_of_chunks = (int)((float)ft_lstsize(*stack_a) * 0.02 + 3);
	while (j <= nbr_of_chunks)
	{
		head = *stack_a;
		chunks_count = ft_lstsize(*stack_a) * j / nbr_of_chunks;
		while (head != NULL)
		{
			if (head->rank > chunks_count)
				head->chunk = j;
			head = head->next;
		}
		j++;
	}
}
