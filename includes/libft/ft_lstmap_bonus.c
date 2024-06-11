/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-oirg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:12:49 by zel-oirg          #+#    #+#             */
/*   Updated: 2023/11/29 22:21:36 by zel-oirg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	clean(t_list *curr, t_list *res, void (*del)(void *))
{
	while (res)
	{
		curr = res->next;
		(*del)(res->content);
		free(res);
		res = curr;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*curr;
	void	*content;

	if (!f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		content = f(lst->content);
		curr = ft_lstnew(content);
		if (!curr)
		{
			del(content);
			clean(curr, res, del);
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&res, curr);
		lst = lst->next;
	}
	return (res);
}
