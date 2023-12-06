/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:34:18 by mzelouan          #+#    #+#             */
/*   Updated: 2023/12/06 15:00:07 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void read_line_fd(char **stash, int fd)
{
    char *holder;
    int read_count;

    holder = NULL;
    while (!ft_strchr(*stash, '\n'))
    {
        holder = malloc(BUFFER_SIZE + 1);
        if (holder == NULL)
            return ;
        read_count = read(fd, holder, BUFFER_SIZE);
        if (read_count <= 0)
        {
            free(holder);
            return ;
        }
        holder[read_count] = '\0';
        *stash = ft_strjoin(*stash, holder);
        free(holder);
    }
}

char *extract_line(char *stash)
{
    char *line;
    int i;

    line = NULL;
    i = 0;
    if (!ft_strlen(stash))
		return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    line = malloc(i + 1);
    if (line == NULL)
        return(NULL);
    i = -1;
    while (stash[++i] && stash[i] != '\n')
        line[i] = stash[i];
    if (stash[i] && stash[i] == '\n')
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';
    return(line);
}

char *clean_stash(char *stash)
{
    char *holder;
    int i;
    int j;

    i = 0;
    j = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (stash[i] && stash[i] == '\n')
        i++;
    holder = malloc((ft_strlen(stash) - i) + 1);
    if (holder == NULL)
        return (NULL);
    while (stash[i])
    {
        holder[j] = stash[i];
        j++;
        i++;
    }
    holder[j] = '\0';
    free(stash);
    return (holder);
}

char *get_next_line(int fd)
{
    static char *stash[1024];
    char *line;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
        return (NULL);
    // 1 == read line from fd
    read_line_fd(&stash[fd], fd);
    if (stash == NULL)
        return(NULL);
    // 2 == extract line
    line = extract_line(stash[fd]);
    // 3 == clean stash
    // if (line[0] == '\0')
    // {
    //     free(array_of_stash[fd]);
    //     //free(stash);
    //     free(line);
    //     return(NULL);
    // }
    if (line == NULL)
    {
        free(stash[fd]);
        return (NULL);
    }
    stash[fd] = clean_stash(stash[fd]);
    //printf("%s\n", stash);
    return (line);
}