/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:36:55 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/26 09:04:49 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
@brief Assign ranks to elements in the stack.
This function assigns ranks to the elements in the stack based on their
content values. The rank of an element represents the number of elements
in the stack that have a smaller content value.
@param stack The stack to assign ranks to.
*/
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

/*
@brief Initialize chunks for elements in the stack.
This function initializes chunks for the elements in the stack based on the
specified algorithm. It calculates the number of chunks based on a percentage
of the stack size, and assigns a chunk number to each element based on its rank.
@param stack_a The stack to initialize the chunks for.
*/

void	chunk_init(t_list **stack_a)
{
	t_list	*head;
	int		nbr_of_chunks;
	int		chunks_count;
	int		j;

	j = 1;
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
