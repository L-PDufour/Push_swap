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
void check_for_duplicates(t_list *stack);
t_list *stack_init(int argc, char **argv, t_list *stack);

#endif
