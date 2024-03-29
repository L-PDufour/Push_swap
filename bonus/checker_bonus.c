/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 09:16:43 by ldufour           #+#    #+#             */
/*   Updated: 2023/06/06 14:05:07 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_move(t_list **stack_a, t_list **stack_b, char *line, int len)
{
	if (ft_strncmp("pa", line, len) == 0)
		move_push(stack_b, stack_a);
	else if (ft_strncmp("pb", line, len) == 0)
		move_push(stack_a, stack_b);
	else if (ft_strncmp("rra", line, len) == 0 || ft_strncmp("rrb", line,
			len) == 0 || ft_strncmp("rrr", line, len) == 0)
		do_reverse_rotate(stack_a, stack_b, line, len);
	else if (ft_strncmp("ra", line, len) == 0 || ft_strncmp("rb", line,
			len) == 0 || ft_strncmp("rr", line, len) == 0)
		do_rotate(stack_a, stack_b, line, len);
	else if (ft_strncmp("sa", line, len) == 0 || ft_strncmp("sb", line,
			len) == 0 || ft_strncmp("ss", line, len) == 0)
		do_swap(stack_a, stack_b, line, len);
	else
	{
		free(line);
		error(*stack_a);
	}
}

static void	move_reader(t_list **stack_a, t_list **stack_b, int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (i == 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			i = 1;
			break ;
		}
		do_move(stack_a, stack_b, line, ft_strlen(line) - 1);
		free(line);
	}
	free(line);
	if (check_if_sorted(stack_a) == 1)
		printf("OK\n");
	else
		printf("KO\n");
}

static void	parsing_checker(t_list *stack)
{
	if (!check_if_int(stack))
	{
		error(stack);
		exit(0);
	}
	if (check_for_duplicates(stack))
	{
		error(stack);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	stack_a = stack_init(argc, argv, stack_a);
	parsing_checker(stack_a);
	move_reader(&stack_a, &stack_b, 0);
	ft_lstfree(stack_a);
	ft_lstfree(stack_b);
	return (0);
}
