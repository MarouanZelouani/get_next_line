/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:51:34 by mzelouan          #+#    #+#             */
/*   Updated: 2023/11/29 16:25:35 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

char *get_next_line(int fd);
char * ft_read_fd(t_list **lst, int fd);
char *ft_extract_line_fd(t_list *lst);
void ft_clear_all_fd(t_list **lst);
void ft_add_to_lst(t_list **lst, char *holder, int read_cout);
int found_newline(t_list *lst);
t_list *ft_get_last_node(t_list *lst);
void ft_allocat_line(t_list *lst, char **line);
size_t	ft_strlen(const char *s);
void ft_free_list(t_list **lst, t_list *current, int op);

#endif