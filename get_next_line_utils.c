/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:51:31 by mzelouan          #+#    #+#             */
/*   Updated: 2023/11/28 05:10:58 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// search for a new line character inside a node content

// create a new node

// add a node in the back of the linked list
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new != NULL)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			node = *lst;
			while (node->next != NULL)
			{
				node = node->next;
			}
			node->next = new;
		}
	}
}

