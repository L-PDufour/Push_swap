/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 15:06:03 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/16 15:25:00 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft42/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	move_swap(t_list **stack);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	move_rotate(t_list **stack);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	move_reverse_rotate(t_list **stack);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);
void	move_push(t_list **stack_from, t_list **stack_to);
void	pa(t_list **stack_b, t_list **stack_a);
void	pb(t_list **stack_a, t_list **stack_b);
int		check_if_sorted(t_list *stack);
void	check_for_duplicates(t_list *stack);
t_list	*stack_create(int data, char **argv_copy, int j, t_list *new_node, t_list *stack);
void	parsing(t_list *stack);
t_list	*stack_init(int argc, char **argv, t_list *stack);
void	tiny_sort(t_list **stack_a);
void	medium_sort(t_list **stack_a, t_list **stack_b);
void	big_sort(t_list **stack_a, t_list **stack_b);
void big_sort_stack_b (t_list **stack_a, t_list **stack_b);
t_list	*find_smallest_rank(t_list **stack_a);
int		update_index(t_list *stack);
t_list	*find_best_rank(t_list **stack_a, int key_nbr);
void	rank_final(t_list **stack);
int		find_highest_position(t_list *stack);
void	find_best_node(t_list **stack, int chunks);
t_list	*find_last_node(t_list **stack, int chunks);
t_list	*find_first_node(t_list **stack, int chunks);
t_list	*find_highest_rank(t_list **stack);
void	error(t_list *stack);
void	free_error(char **array, t_list *stack);

#endif
