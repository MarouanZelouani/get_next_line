/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:51:28 by mzelouan          #+#    #+#             */
/*   Updated: 2023/11/26 23:31:19 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    char * line_holder;
    
    if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, line_holder, 0))
        return (NULL);
    
    
}