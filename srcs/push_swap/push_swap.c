
#include "../../includes/push_swap.h"

int main(int argc, char **argv) {
  t_list *stack_a;
  t_list *stack_b;

  stack_a = NULL;
  stack_b = NULL;
  if (argc <= 1)
    return (1);
  stack_a = stack_init(argc, argv, stack_a);
  check_for_duplicates(stack_a);
  if (check_if_sorted(stack_a) == 0)
    return (1);
  move_swap(stack_a);
  move_push(stack_a, stack_b);
  print_stack(stack_a);
  return (0);
}
