/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:36:55 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 10:40:45 by ldufour          ###   ########.fr       */
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

/*
@brief Initialize the stack with values from command-line arguments.
This function initializes the stack by parsing the command-line arguments
and adding the values to the stack.
@param argc The number of command-line arguments.
@param argv The array of command-line argument strings.
@param stack The initial stack to populate.
@return The updated stack after adding values from the arguments.
 */
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
			data = ft_atol(argv_copy[j]);
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

/*
@brief Convert a string to a long integer.
This function takes a string representation of an integer and converts it
to a long integer value. It supports positive and negative numbers within
the range of LONG_MIN and LONG_MAX.
@param str The string to convert to a long integer.
@param array The array of strings (for error handling).
@param stack The stack (for error handling).
@return The converted long integer value.
*/
long	ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	if (!str || ft_strlen(str) == 0 || ft_strlen(str) > 11)
		return (LONG_MAX);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == 45)
	{
		sign *= -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (LONG_MAX);
	while (ft_isdigit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (LONG_MAX);
	return (result * sign);
}
