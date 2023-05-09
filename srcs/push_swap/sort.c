#include "../../includes/push_swap.h"

void tiny_sort(t_list **stack_a) {
  if (*stack_a == NULL || (*stack_a)->next == NULL)
    return;
  if (((*stack_a)->content > (*stack_a)->next->content) &&
      ((*stack_a)->next->content < (*stack_a)->next->next->content))
    sa(stack_a);
  if (((*stack_a)->content > (*stack_a)->next->content) &&
      ((*stack_a)->next->content > (*stack_a)->next->next->content)) {
    sa(stack_a);
    rra(stack_a);
  }
  if (((*stack_a)->content > (*stack_a)->next->content) &&
      ((*stack_a)->next->content < (*stack_a)->next->next->content))
    ra(stack_a);
  if (((*stack_a)->content < (*stack_a)->next->content) &&
      ((*stack_a)->next->content > (*stack_a)->next->next->content) &&
      ((*stack_a)->content < (*stack_a)->next->next->content)) {
    sa(stack_a);
    ra(stack_a);
  }
  if (((*stack_a)->content < (*stack_a)->next->content) &&
      ((*stack_a)->next->content > (*stack_a)->next->next->content) &&
      ((*stack_a)->content > (*stack_a)->next->next->content))
    rra(stack_a);
}

void big_sort(t_list **stack_a, t_list **stack_b) {
  if (*stack_a == NULL || (*stack_a)->next == NULL)
    return;
  while (ft_lstsize(*stack_b) != 2) {
    pb(stack_a, stack_b);
  }
  while (ft_lstsize(*stack_b) != 0) {
    pa(stack_b, stack_a);
    tiny_sort(stack_a);
  }
  // recursivite
  //  tiny_sort(stack_a);
}
