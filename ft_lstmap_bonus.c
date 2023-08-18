/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcesar-v <vcesar-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:59:07 by victorcvaz        #+#    #+#             */
/*   Updated: 2023/08/17 21:53:17 by vcesar-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*curr_node;

	if (!lst || !f || !del)
		return (NULL);
	new_node = NULL;
	while (lst)
	{
		curr_node = ft_lstnew(f(lst->content));
		if (!curr_node)
		{
			ft_lstclear(&new_node, del);
			return (NULL);
		}
		ft_lstadd_back(&new_node, curr_node);
		lst = lst->next;
	}
	return (new_node);
}