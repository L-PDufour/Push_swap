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
	int i;
	int data;
	data = 0;
	i = 0;

	a = NULL;

	while (i < argc - 1)
	{
		data = ft_atoi(argv[i + 1]);
		new_node = ft_lstnew(data);
		ft_lstadd_back(&a, new_node);
		i++;
	}
	ft_lstiter(a, print_data);
	return (0);
}
