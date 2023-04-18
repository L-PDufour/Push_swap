#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void print_data(void *data) { printf("%s\n", (char *)data); }

int main(int argc, char **argv) {

  int i = 1;

  t_list *a = NULL;
  if (argc == 1 || (argc == 2 && !argv[1][0])) {
    printf("1\n");
    return (1);
  }
  argv = ft_split(*argv, ' ');
  while (argv[i] != NULL) {
    t_list *new_node = ft_lstnew(*argv);
    ft_lstadd_front(&a, new_node);
    i++;
  }
  ft_lstiter(a, print_data);

  return (0);
}
