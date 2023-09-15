/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr < yel-hadr@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 06:58:55 by elakhfif          #+#    #+#             */
/*   Updated: 2023/09/13 06:43:19 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ptr;

	ptr = (t_list *)(ft_calloc(sizeof(t_list), 1));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}
/*
int main()
{
	t_list	*a;
	t_list	*b;
	t_list	*head;

	a = ft_lstnew("tarzan");
	b = ft_lstnew("Houscein");

	a->next = b;
	head = a;
	while (head)
	{
		printf("%s", head->content);
		head = head->next;
	}
}
*/
