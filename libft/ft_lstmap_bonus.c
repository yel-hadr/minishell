/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:32:24 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/10/17 17:16:42 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	list = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			tmp = ft_lstnew(f(lst->content));
			if (tmp == NULL)
			{
				ft_lstclear(&list, del);
				return (NULL);
			}
			ft_lstadd_back(&list, tmp);
			lst = lst->next;
		}
	}
	return (list);
}
