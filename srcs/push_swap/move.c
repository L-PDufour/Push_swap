#include "../../includes/push_swap.h"

void move_swap(t_list *stack) {
  int tmp;

  tmp = stack->content;
  stack->content = stack->next->content;
  stack->next->content = tmp;
}

void sa(t_list **stack) {
  move_swap(*stack);
  printf("sa\n");
}

void sb(t_list *stack) {
  move_swap(stack);
  printf("sb\n");
}

void ss(t_list *stack_a, t_list *stack_b) {
  move_swap(stack_a);
  move_swap(stack_b);
  printf("ss\n");
}

void move_push(t_list *a, t_list *b) {
  t_list *tmp;

  if (b == NULL)
    return;
  tmp = b;
  b = b->next;
  a = tmp;
}

void move_rotate(t_list **stack) {
  t_list *first;
  t_list *last;

  if (*stack == NULL || (*stack)->next == NULL)
    return;
  first = *stack;
  *stack = (*stack)->next;
  last = *stack;
  while (last->next != NULL)
    last = last->next;
  last->next = first;
  first->next = NULL;
}

void ra(t_list **stack) {
  move_rotate(stack);
  printf("ra\n");
}

void rb(t_list **stack) {
  move_rotate(stack);
  printf("rb\n");
}

void rr(t_list **stack_a, t_list **stack_b) {
  move_rotate(stack_a);
  move_rotate(stack_b);
  printf("rr\n");
}

void move_reverse_rotate(t_list **stack) {
  t_list *last;
  t_list *prev_last;

  if (*stack == NULL || (*stack)->next == NULL)
    return;
  last = *stack;
  prev_last = NULL;
  while (last->next != NULL) {
    prev_last = last;
    last = last->next;
  }
  prev_last->next = NULL;
  last->next = *stack;
  *stack = last;
}

void rra(t_li)
