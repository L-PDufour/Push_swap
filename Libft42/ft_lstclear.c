/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldufour <marvin@42quebec.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 08:34:23 by ldufour           #+#    #+#             */
/*   Updated: 2023/03/06 12:54:10 by ldufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst) {
  t_list *tmp;

  if (!lst)
    return;
  while (*lst) {
    tmp = (*lst)->next;
    free((*lst));
    *lst = tmp;
  }
  *lst = NULL;
}
