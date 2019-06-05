/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhernand <mhernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:50:30 by mhernand          #+#    #+#             */
/*   Updated: 2019/03/20 13:19:44 by mhernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*tmp;

	if (!(tmp = malloc(sizeof(t_list))))
		return (NULL);
	if ((content_size == 0) || (content == NULL))
	{
		tmp->content = NULL;
		tmp->next = NULL;
	}
	else
	{
		tmp->content = malloc(sizeof(content_size));
		tmp->content = ft_memcpy(tmp->content, content, content_size);
		if (!tmp->content)
			return (NULL);
		tmp->next = NULL;
	}
	return (tmp);
}
