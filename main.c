#include "libft/ft_bzero.c"
#include "libft/ft_calloc.c"
#include "libft/ft_split.c"
#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void print_data(int data) { printf("%i\n", data); }

int ft_strcmp(const char *s1, const char *s2) {
  while (*s1 && (*s1 == *s2)) {
    ++s1;
    ++s2;
  }
  return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
int check_duplicates(char **array) {
  int i;
  int j;
  i = 0;
  while (array[i] != NULL) {
    j = i + 1;
    while (array[j] != NULL) {
      if (ft_strcmp(array[i], array[j]) == 0) {
        return (1);
      }
      j++;
    }
    array++;
  }
  return (0);
}

int main(int argc, char **argv) {
  t_list *a;
  t_list *new_node;
  char **argv_copy = NULL;
  int i;
  int j;
  long data;
  data = 0;
  i = 1;

  a = NULL;
  if (argc == 1) {
    printf("Error");
    return (1);
  }
  while (i < argc) {
    argv_copy = ft_split(argv[i], ' ');
    j = 0;
    while (argv_copy[j]) {
      data = ft_atoi(argv_copy[j]);
      if (data >= INT_MAX || data <= INT_MIN)
        return (1);
      new_node = ft_lstnew(data);
      ft_lstadd_back(&a, new_node);
      j++;
    }
    i++;
  }
  ft_lstiter(a, print_data);
  return (0);
}
