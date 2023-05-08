#include "../../includes/push_swap.h"

void tiny_sort(t_list **stack_a) {
  if (*stack_a == NULL || (*stack_a)->next == NULL)
    return;
  if (((*stack_a)->content > (*stack_a)->next->content) &&
      ((*stack_a)->content < (*stack_a)->next->next->content))
    sa(stack_a);
  else if (((*stack_a)->content < (*stack_a)->next->content) &&
           ((*stack_a)->content < (*stack_a)->next->next->content)) {
    sa(stack_a);
    rra(stack_a);
  } else if (((*stack_a)->content < (*stack_a)->next->content) &&
             ((*stack_a)->next->content > (*stack_a)->next->next->content))
    ra(stack_a);
}
