
#include "../../includes/push_swap.h"

// Errors include for example: some arguments aren’t integers,
// some arguments are
// bigger than an integer and/or there are duplicates

void	print_data(int data)
{
	printf("%i\n", data);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*new_node;
	char	**argv_copy;
	int		i;
	int		j;
	long	data;

	argv_copy = NULL;
	data = 0;
	i = 1;
	a = NULL;
	if (argc <= 1)
		return (1);
	while (i < argc)
	{
		argv_copy = ft_split(argv[i], ' ');

		j = 0;
		while (argv_copy[j])
		{
			data = ft_atoi(argv_copy[j]);
			if (!(data >= INT_MIN && data <= INT_MAX))
			{
				ft_putstr_fd("Error\n", 2);
				exit(1);
			}
			new_node = ft_lstnew(data);
			ft_lstadd_back(&a, new_node);
			j++;
		}
		i++;
	}
	ft_lstiter(a, print_data);
	return (0);
}
