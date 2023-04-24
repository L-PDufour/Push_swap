#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	print_data(void *data)
{
	printf("%s\n", (char *)data);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*a;
	t_list	*new_node;

	i = 1;
	a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		printf("1\n");
		return (1);
	}
	while (argv[i] != NULL)
	{
		new_node = ft_lstnew(argv[i]);
		ft_lstadd_front(&a, new_node);
		i++;
	}
	ft_lstiter(a, print_data);
	// argv = ft_split(argv[i], 32);

	// while (**argv)
	// {
	// 	printf("%s", argv[i]);
	// 	i++;
	// }
	return (0);

}
