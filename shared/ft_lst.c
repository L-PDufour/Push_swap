/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:49:45 by ldufour           #+#    #+#             */
/*   Updated: 2023/05/31 16:41:07 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
Counts the number of elements in a linked list.
@param lst The linked list.
@return    The number of elements in the linked list.
*/
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
Creates a new node for a linked list with the specified content.
@param content The content of the node.
@return        The newly created node.
*/
t_list	*ft_lstnew(long content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->rank = 0;
	tmp->cost = 0;
	tmp->steps = 0;
	tmp->chunk = 0;
	tmp->next = NULL;
	return (tmp);
}

/*
Creates a new node for a linked list with the specified content.
@param content The content of the node.
@return        The newly created node.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!new || !lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

/*
Frees the memory occupied by a linked list.
@param list The linked list to be freed.
*/
void	ft_lstfree(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

/*
Returns the last node of a linked list.
@param lst The linked list.
@return The last node of the linked list.
*/
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
