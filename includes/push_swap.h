#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include "../libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void move_swap(t_list *a);
void sa(t_list **a);
void sb(t_list *a);
void ss(t_list *a, t_list *b);
void move_push(t_list *a, t_list *b);
void free_error(char **array, t_list *stack);
void print_stack(t_list *stack);
int check_if_sorted(t_list *stack);
void check_for_errors(t_list *stack);
t_list *stack_init(int argc, char **argv, t_list *stack);
void move_rotate(t_list **stack);
void ra(t_list **stack);
void rb(t_list **stack);
void move_reverse_rotate(t_list **stack);
void rr(t_list **stack_a, t_list **stack_b);
#endif
