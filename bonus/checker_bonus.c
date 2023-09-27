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

static void	do_reverse_rotate(t_list *stack_a, t_list *stack_b, char *line,
		int len)
{
	if (ft_strncmp("rra", line, len) == 0)
		move_reverse_rotate(&stack_a);
	else if (ft_strncmp("rrb", line, len) == 0)
		move_reverse_rotate(&stack_b);
	else if (ft_strncmp("rrr", line, len) == 0)
	{
		move_reverse_rotate(&stack_a);
		move_reverse_rotate(&stack_b);
	}
}

static void	do_rotate(t_list *stack_a, t_list *stack_b, char *line, int len)
{
	if (ft_strncmp("ra", line, len) == 0)
		move_rotate(&stack_a);
	else if (ft_strncmp("rb", line, len) == 0)
		move_rotate(&stack_b);
	else if (ft_strncmp("rr", line, len) == 0)
	{
		move_rotate(&stack_a);
		move_rotate(&stack_b);
	}
}

static void	do_swap(t_list *stack_a, t_list *stack_b, char *line, int len)
{
	if (ft_strncmp("sa", line, len) == 0)
		move_swap(&stack_a);
	else if (ft_strncmp("sb", line, len) == 0)
		move_swap(&stack_b);
	else if (ft_strncmp("ss", line, len) == 0)
	{
		move_swap(&stack_a);
		move_swap(&stack_b);
	}
}

static void	do_move(t_list *stack_a, t_list *stack_b, char *line, int len)
{
	if (ft_strncmp("pa", line, len) == 0)
		move_push(&stack_b, &stack_a);
	else if (ft_strncmp("pb", line, len) == 0)
		move_push(&stack_a, &stack_b);
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
		error(stack_a);
}

void	move_reader(t_list *stack_a, t_list *stack_b)
{
	char	*line;
	int		progress;

	line = NULL;
	// free(line);
	progress = 1;
	while (progress == 1)
	{
		line = get_next_line(0);
		do_move(stack_a, stack_b, line, ft_strlen(line) - 1);
		if (line == NULL)
			progress = 0;
	}
	free(line);
}

void	parsing_checker(t_list *stack)
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
void	printStack(t_list *stack)
{
	t_list	*current;

	current = stack;
	printf("Stack elements: ");
	while (current != NULL)
	{
		printf("%ld ", current->content);
		current = current->next;
	}
	printf("\n");
}
// Je perds la tête de la stack
// Oublie de mettre un double pointeur
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc <= 1)
		return (0);
	stack_a = stack_init(argc, argv, stack_a);
	parsing_checker(stack_a);
	move_reader(stack_a, stack_b);
	printStack(stack_a);
	if (check_if_sorted(stack_a) == 1)
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
