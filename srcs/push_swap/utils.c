#include "../../includes/push_swap.h"
#include <unistd.h>

void print_stack(t_list *stack) {
  while (stack != NULL) {
    printf("%i\n", stack->content);
    printf("%i\n", stack->position);
    stack = stack->next;
  }
}

void free_error(char **array, t_list *stack) {
  int i;

  i = 0;
  while (array[i]) {
    free(array[i]);
    i++;
  }
  ft_lstclear(&stack);
  ft_putstr_fd("Error\n", STDERR_FILENO);
  exit(1);
}
