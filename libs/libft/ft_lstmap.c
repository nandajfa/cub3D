/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esilva-s <esilva-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/25 13:17:32 by esilva-s          #+#    #+#             */
/*   Updated: 2022/03/06 19:10:55 by esilva-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*next_element;
	t_list	*current;

	if (lst == NULL || f == NULL)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!(result))
		return (NULL);
	current = result;
	lst = lst->next;
	while (lst)
	{
		next_element = ft_lstnew(f(lst->content));
		if (next_element == NULL)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		current->next = next_element;
		current = next_element;
		lst = lst->next;
	}
	return (result);
}
