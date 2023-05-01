
#include "../../includes/push_swap.h"

// bigger than an integer and/or there are duplicates
// J'ai bcp changé de libft. regarder avec un diff pour savoir si tout
// est beau. ft_atoi tout ce qui est bonus.

void	print_data(int data)
{
	printf("%i\n", data);
}

void	free_error(char **str, t_list *a)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	ft_lstclear(&a);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	stack_init(int argc, char **argv, t_list *new_node, t_list *a)
{
	int		i;
	int		j;
	long	data;
	char	**argv_copy;

	data = 0;
	i = 1;
	argv_copy = NULL;
	while (i < argc)
	{
		argv_copy = ft_split(argv[i], ' ');
		j = 0;
		while (argv_copy[j])
		{
			data = ft_atoi(argv_copy[j]);
			if (!(data >= INT_MIN && data <= INT_MAX))
				free_error(argv_copy, a);
			new_node = ft_lstnew(data);
			ft_lstadd_back(&a, new_node);
			j++;
		}
		i++;
	}
	ft_lstiter(a, print_data);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*new_node;

	a = NULL;
	if (argc <= 1)
		return (1);
	stack_init(argc, argv, new_node, a);
	return (0);
}
