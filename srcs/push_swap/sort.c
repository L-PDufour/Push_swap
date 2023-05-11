#include "../../includes/push_swap.h"

void	tiny_sort(t_list **stack)
{
	int	highest_position;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	highest_position = find_highest_position(*stack);
	if ((*stack)->rank == highest_position)
		ra(stack);
	else if ((*stack)->next->rank == highest_position)
		rra(stack);
	if ((*stack)->rank > (*stack)->next->rank)
		sa(stack);
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	while ((ft_lstlast(*stack_a))->rank != 0)
		ra(stack_a);
	while ((ft_lstsize(*stack_a)) > 3)
		pb(stack_a, stack_b);
	tiny_sort(stack_a);
	t_list *tmp_b;
    while (*stack_b)
    {
        tmp_b = *stack_b;
        if ((tmp_b->rank < (*stack_a)->rank) && (tmp_b->rank > (ft_lstlast(*stack_a)->rank)))
            pa(stack_b, stack_a);
        else
            rra(stack_a);
    }
}

int	find_highest_position(t_list *stack)
{
	int	position;

	position = stack->rank;
	while (stack)
	{
		{
			if (stack->rank > position)
				position = stack->rank;
			stack = stack->next;
		}
	}
	return (position);
}

int	find_smallest_value(t_list **stack_a)
{
	int		min_value;
	t_list	*current;

	if (*stack_a == NULL)
		return (0);
	min_value = (*stack_a)->content;
	current = (*stack_a)->next;
	while (current != NULL)
	{
		if (current->content < min_value)
			min_value = current->content;
		current = current->next;
	}
	return (min_value);
}

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

void	rank_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*checker;

	tmp = *stack;
	while (tmp)
	{
		tmp->position = 0;
		checker = *stack;
		while (checker)
		{
			if (tmp->content > checker->content)
				tmp->position += 1;
			checker = checker->next;
		}
		tmp = tmp->next;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*head_b;

	rank_stack(stack_a);
	head = (*stack_a);
	head_b = (*stack_b);
	while ((head)->next != NULL)
	{
		if ((ft_lstlast(head)->position) <= (head)->position)
			ra(&head);
		else
		{
			pb(&head, stack_b);
			rb(stack_b);
		}
		head = head->next;
	}
	head = (*stack_a);
	// while ((head_b)->next != NULL)
	// {
	//     if ((head)->position < (*stack_b)->position)
	//       pb(&head, stack_b);
	// rb(stack_b);
	// while ((*stack_b)->position > (ft_lstlast(*stack_b)->position)) {
	//   if ((*stack_a)->position < (*stack_b)->position)
	//     pb(stack_a, stack_b);
	//   rb(stack_b);
	// }
	// while ((ft_lstlast(*stack_b)->position) < (*stack_a)->position) {
	//   pb(stack_a, stack_b);
	//   rb(stack_b);
	// }
	// head_b= head_b->next;
	// }
}

/* Initial stage : */
/*  - parse parameters */
/*  - Creation of a stack A which is a circular doubly linked list (last.next
 * = first; first.prec = last */
/*  - Addition in the struct of a rank component, integer from 1 to n. */
/* This will be much more practical later. */
/* Phase 1 : */
/*  - Split the list into 3 (modifiable parameter in the .h). */
/*  - Push the 2 smallest thirds into stack B and do a pre-sort. do ra with
 * others */
/*  - Repeat the operation until there are only 3 numbers left in stack A. */
/*  - Sort these 3 numbers with a specific algo (2 operations maximum) */
/* Phase2: */
/*  (Only the ra/rra/rb/rrb commands are used. sa and sb are not used in this
 * phase) */
/*  - Swipe B and look for the number that will take the fewest moves to be
 * pushed into A. */
/*  There are each time 4 ways to bring a number from B to A: ra+rb, ra+rrb,
 * rra+rb, rra+rrb. We are looking for the mini between these 4 ways. */
/*  - Then perform the operation. */
/*  - Repeat the operation until empty B. */
/* Phase 3: If necessary rot stack A to finalize the correct order. The
 * shorter between ra or rra. */
/* The optimization comes from the fact of the maximum use of the double
 * rotations rr and rrr */
