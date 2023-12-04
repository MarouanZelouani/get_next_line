/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:38:51 by mzelouan          #+#    #+#             */
/*   Updated: 2023/12/04 05:11:31 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <limits.h>

char *get_next_line(int fd)
{
    static t_list *list_of_lst[1024]; 
    t_list *lst;
    char *line;

    lst = list_of_lst[fd];
    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) == -1)
        return (NULL);
    ft_read_fd(&lst, fd);
	// if (line != NULL)
    // {
    //     list_of_lst[fd] = lst;
    //     return (line);
    // }
    if (lst == NULL)
        return (NULL);
    line = ft_extract_line_fd(lst);
    if (line[0] == '\0')
	{
		ft_free_list(&lst, NULL, 0);
		lst = NULL;
		free(line);
        list_of_lst[fd] = lst;
		return (NULL);
	}
    ft_clear_all_fd(&lst);
    list_of_lst[fd] = lst;
    return (line);
}

void ft_read_fd(t_list **lst, int fd)
{
    char *holder;
    int read_count;
    //char *line;

    //line = NULL;
    holder = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (holder == NULL)
        return ;
    while (!found_newline(*lst))
    {
        read_count = read(fd, holder, BUFFER_SIZE);
        if (!read_count)
        {
            free(holder);
			return ;
        }
        holder[read_count] = '\0';
        ft_add_to_lst(lst, holder, read_count);
    }
    free(holder);
	// return (NULL);
}

char *ft_extract_line_fd(t_list *lst)
{
    char *line;
    int i;
    int j;

    ft_allocat_line(lst, &line);
    if (line == NULL)
        return (NULL);
    j = 0;
    while (lst)
    {
        i = 0;
        while (lst->content[i] && lst->content[i] != '\n')
            line[j++] = lst->content[i++];
        if (lst->content[i] == '\n')
            line[j++] = '\n';
        lst = lst->next;
    }
    line[j] = '\0';
    return (line);
}

void ft_allocat_line(t_list *lst, char **line)
{
    int i;
    int len;

    i = 0;
    len = 0;
    while (lst)
    {
        while (lst->content[i] && lst->content[i] != '\n')
        {
            len++;
            i++;
        }
        if (lst->content[i] == '\n')
        {
            len++;
            break ;
        }
        lst = lst->next;
        i = 0;
    }
    *line = malloc((len + 1) * sizeof(char));
}

void ft_clear_all_fd(t_list **lst)
{
    t_list  *current;
    char    *holder;
    char    *new_content;
    int     i;
    int     len;

    current = ft_get_last_node(*lst);
    holder = current->content;
    i = 0;
    while (holder[i] && holder[i] != '\n')
        i++;
    if (holder[i] && holder[i] == '\n')
        i++;
    len = ft_strlen(holder + i);
    new_content = malloc((len + 1) * sizeof(char));
    if (new_content == NULL)
        return ;
    len = 0;
    while (holder[i])
        new_content[len++] = holder[i++];
    new_content[len] = '\0';
    free(current->content);
    current->content = new_content;
	ft_free_list(lst, current, 1);
}