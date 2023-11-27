/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:51:28 by mzelouan          #+#    #+#             */
/*   Updated: 2023/11/27 11:16:49 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static t_list   *lst;
    char            *line;
    int             flag;

    lst = NULL;
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, line, 0) == -1)
        return (NULL);
    // read from fd and add to lst
    ft_read_fd(&lst, &flag, fd);
    if (lst == NULL)
        return (NULL);
    // extract from lst to line (join all the contents)
  	extract_just_line(lst, &line);
    // clean up lst
	clean_up_lst(&lst);
    return (line);
}

void ft_read_fd(t_list **lst, int *flag, int fd)
{
    char *holder;

    holder = (char *) malloc ((BUFFER_SIZE + 1) * sizeof(char));
    if (holder == NULL)
        return (NULL);
    while (!found_new_line(*lst) && *flag != 0)
    {
        *flag = read(fd, holder, BUFFER_SIZE);
        if (*flag == -1 || (*flag == 0 && *lst == NULL))
        {
            free(holder);
            return ;
        }
        holder[*flag] = '\0';
        add_to_list(lst, holder, flag);
        free(holder);
    }
}

void extract_just_line(t_list *lst, char **line)
{
	int i;


	if (lst == NULL)
		return (NULL);
	allocate_line(lst, line);
	if (*line == NULL)
		return(NULL);
	i = 0;
	while (lst)
	{
		while (lst->content[i] && lst->content[i] != '\n')
		{
			(*line)[i] = lst->content[i];
			i++;
		}	
		lst = lst->next;
	}
	(*line)[i] = '\n';
	(*line)[i + 1] = '\0';
}

void allocate_line(t_list *lst, char **line)
{
	int len;
	int i;

	len = 1;
	i = 0;
	while (lst)
	{
		while (lst->content[i])
		{
			if(lst->content[i] != '\n')
				len++;
			i++;
		}
		lst = lst->next;
	}
	*line = (char *)malloc((len + 1) * sizeof(char));
}

void clean_up_lst(t_list **lst)
{
	t_list *node;
	t_list *next;
	char *holder;
	int i;
	int flag;
	int len;

	
	node = *lst;
	flag = 0;
	while (node && !found_new_line(*node))
	{
		next = node->next;
		free(node->content);
		free(node);
		node = next;
		node = node->next;
	}
	
	i = 0;
	len = 0;
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			flag = 1;
		if (flag == 1)
			
		i++;
	}
}

int found_new_line(t_list *lst)
{
    t_list *node;
	int i;

	i = 0;
    if (lst == NULL)
        return (0);
    node = get_last_node(lst);
	while (node->content[i])
	{
		if (node->content[i] == '\n')
			return (1);
		i++;
	}
    return (0);
}

void add_to_list(t_list **lst,char *holder, int *flag)
{
    t_list *new;
    t_list	*node;
    int i;

    new = (t_list *)malloc(sizeof(t_list));
    if (new == NULL)
        return ;
    new->next == NULL;
    new->content = (char *)malloc((*flag + 1) * sizeof(char));
    if (new->content == NULL)
        return ;
    i = 0;
    while (holder[i] && i < *flag)
    {
        new->content[i] = holder[i];
        i++;
    }
    new->content[i] = '\0';
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

t_list	*get_last_node(t_list *lst)
{
	t_list	*node;

	node = NULL;
	while (lst)
	{
		if (lst->next == NULL)
			node = lst;
		lst = lst->next;
	}
	return (node);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
    if (s == NULL)
        return (NULL);
	while (s[len])
		len++;
	return (len);
}

