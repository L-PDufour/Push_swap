
#include "../../includes/push_swap.h"

int check_if_sorted(t_list *stack) {
  int i = 0;
  while (stack->next != NULL) {
    if (stack->number > stack->next->number)
      i++;
    stack = stack->next;
  }
  return (i);
}

void check_for_duplicates(t_list *stack) {
  while (stack->next != NULL) {
    if (stack->number == stack->next->number) {
      ft_lstclear(&stack);
      ft_putstr_fd("Error\n", 1);
      exit(1);
    }
    stack = stack->next;
  }
}

t_list *stack_init(int argc, char **argv, t_list *stack) {
  int i;
  int j;
  long data;
  char **argv_copy;
  t_list *new_node;

  data = 0;
  i = 1;
  argv_copy = NULL;
  while (i < argc) {
    argv_copy = ft_split(argv[i], ' ');
    j = 0;
    while (argv_copy[j]) {
      data = ft_atoi(argv_copy[j]);
      if (!(data >= INT_MIN && data <= INT_MAX))
        free_error(argv_copy, stack);
      new_node = ft_lstnew(data);
      ft_lstadd_back(&stack, new_node);
      j++;
    }
    i++;
  }
  return (stack);
}
