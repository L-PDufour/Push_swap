#include "../../includes/push_swap.h"

void move_swap(t_list *a) {
  int tmp;

  tmp = a->number;
  a->number = a->next->number;
  a->next->number = tmp;
}

void sa(t_list **a) {
  move_swap(*a);
  printf("sa\n");
}

void sb(t_list *a) {
  move_swap(a);
  printf("sb\n");
}

void ss(t_list *a, t_list *b) {
  move_swap(a);
  move_swap(b);
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
