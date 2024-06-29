/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamiano <ntamiano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 04:41:23 by ntamiano          #+#    #+#             */
/*   Updated: 2023/01/26 05:55:57 by ntamiano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list	*lst2;

	if (!lst || !del)
		return ;
	lst2 = lst;
	if (lst)
	{
		lst = lst2->next;
		del(lst2->content);
		free(lst2);
	}
}
