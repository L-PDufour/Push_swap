#include "libft/ft_bzero.c"
#include "libft/ft_calloc.c"
#include "libft/ft_split.c"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_data(void *data)
{
	printf("%i\n", (int)data);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*new_node;

	// char	**argv_copy;
	// t_list	*a;
	// t_list	*new_node;
	// a = NULL;
	// argv_copy = NULL;
	// int i, j, data;
	int i;
	int data;
	data = 0;
	i = 1;
	// j = 0;
	// data = 0;
	// while (i < argc - 1)
	// {
	// 	// argv_copy = ft_split((argv[i + 1]), ' ');
	// 	argv_copy[j] = argv[i + 1];
	// 	while (argv_copy[j])
	// 	{
	// 		data = ft_atoi(argv_copy[j]);
	// 		new_node = ft_lstnew(argv_copy);
	// 		ft_lstadd_front(&a, new_node);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// ft_lstiter(a, print_data);
	//  int i = 1;
	a = NULL;
	// if (argc == 1 || (argc == 2 && !argv[1][0]))
	// {
	// 	printf("1\n");
	// 	return (1);
	// }
	// argv = ft_split(*argv, ' ');
	while (argv[i] != NULL)
	{
		data = ft_atoi(argv[i]);
		printf("%i", data);
		int *data_ptr = &data;
		new_node = ft_lstnew(data_ptr);
		// printf("%i\n", new_node->(content));
		ft_lstadd_front(&a, new_node);
		i++;
	}
	ft_lstiter(a, print_data);
	printf("Atoi donne pour 1 : %i\n", ft_atoi("1"));
	return (0);
}
