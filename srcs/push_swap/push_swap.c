
#include "../../includes/push_swap.h"

int main(int argc, char **argv) {
  t_list *stack_a;
  t_list *stack_b;

  stack_a = NULL;
  stack_b = NULL;
  if (argc <= 1)
    return (1);
  stack_a = stack_init(argc, argv, stack_a);
  check_for_errors(stack_a);
  if (check_if_sorted(stack_a) == 0) {
    ft_lstclear(&stack_a);
    return (1);
  }
  if (ft_lstsize(stack_a) == 2)
    sa(&stack_a);
  print_stack(stack_a);
  tiny_sort(&stack_a);
  print_stack(stack_a);
  // implantation de l'algo
  // radix_sort ou divide_conquer
  //

  /* move_swap(stack_a); */
  /* move_rotate(&stack_a); */
  /* move_reverse_rotate(&stack_a); */
  /* print_stack(stack_a); */
  // ft_lstclear(&stack_a);
  // move_push(&stack_a, &stack_b);
  // print_stack(stack_a);
  //  print_stack(stack_a);
  return (0);
}
