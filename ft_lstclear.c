/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dferrari <dferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:57:57 by dferrari          #+#    #+#             */
/*   Updated: 2023/11/19 17:03:04 by dferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*element;
	t_list	*next_el;

	if (lst == 0 || *lst == 0)
	{
		return ;
	}
	element = *lst;
	while (element != 0)
	{
		next_el = element->next;
		if (del != 0)
			del(element->content);
		free(element);
		element = next_el;
	}
	*lst = 0;
}
