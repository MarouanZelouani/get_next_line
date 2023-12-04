/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:39:03 by mzelouan          #+#    #+#             */
/*   Updated: 2023/12/04 02:24:41 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_list *ft_get_last_node(t_list *lst)
{
    t_list	*node;

	node = NULL;
    if (lst == NULL)
    {
        return (NULL);
    }
	while (lst)
	{
		if (lst->next == NULL)
			node = lst;
		lst = lst->next;
	}
	return (node);
}

int found_newline(t_list *lst)
{
    int i;
    t_list *node;
    i = 0;

    node = NULL;
    if (lst == NULL)
        return (0);
    node = ft_get_last_node(lst);
    while (node->content[i])
    {
        if (node->content[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
    if (!s)
    {
        return (0);
    }
	while (s[len])
		len++;
	return (len);
}

void ft_free_list(t_list **lst, t_list *current, int op)
{
	t_list *tmp;

	tmp = NULL;
	if (!op && current == NULL)
	{
    	while ((*lst) != NULL)
    	{
        	tmp = *lst;
        	*lst = (*lst)->next;
        	free(tmp->content);
        	free(tmp);
    	}	
	}
	else if (op && current != NULL)
	{
		while ((*lst) != current)
    	{
        	tmp = *lst;
        	*lst = (*lst)->next;
        	free(tmp->content);
        	free(tmp);
    	}
	}
}

void ft_add_to_lst(t_list **lst, char *holder, int read_count)
{
    t_list *new;
    t_list *node;
    int i;

    i = -1;
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return ;
    new->next = NULL;
    new->content = malloc ((read_count + 1) * sizeof(char));
    new->content[read_count] = '\0';
    if (new->content == NULL)
        return ;
    while (holder[++i] && i < read_count)
        new->content[i] = holder[i];
    if (*lst == NULL)
        *lst = new;
    else
    {
        node = *lst;
        while (node->next != NULL)
            node = node->next;
        node->next = new;
    }
}
