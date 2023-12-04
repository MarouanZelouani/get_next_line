/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:00:37 by mzelouan          #+#    #+#             */
/*   Updated: 2023/12/04 04:20:20 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static t_list *lst; 
    char *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) == -1)
        return (NULL);
    // line = ft_read_fd(&lst, fd);
    ft_read_fd(&lst, fd);
	// if (line != NULL)
    // {
    //     //free(line);
    //     printf("LINE : %s\n", line);
	// 	return (line);
    // }
    if (lst == NULL)
        return (NULL);
    line = ft_extract_line_fd(lst);

    ft_clear_all_fd(&lst);
    if (line[0] == '\0')
	{
		ft_free_list(&lst, NULL, 0);
		lst = NULL;
		free(line);
		return (NULL);
	}
    return (line);
}

void    ft_read_fd(t_list **lst, int fd)
{
    char *holder;
    int read_count;
    //char *line;

    // line = NULL;
    holder = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (holder == NULL)
        return ;
    while (!found_newline(*lst))
    {
        read_count = read(fd, holder, BUFFER_SIZE);
        if (!read_count)
        {
            // printf("maro\n");
            free(holder);
            // line = ft_extract_line_fd(*lst);
			// ft_free_list(lst, NULL, 0);
			// return (line);
            // return (NULL);
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
    
    if (lst == NULL)
        return (NULL);
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

    len = 0;
    while (lst)
    {
        i = 0;
        while (lst->content[i])
		{
			if (lst->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
        lst = lst->next;
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
