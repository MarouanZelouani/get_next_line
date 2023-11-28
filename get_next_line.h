/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 22:51:34 by mzelouan          #+#    #+#             */
/*   Updated: 2023/11/28 19:27:13 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5000
#endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}t_list;

char *get_next_line(int fd);
t_list *get_last_node(t_list *lst);
void add_to_list(t_list **lst,char *holder, int *flag);
int found_new_line(t_list *lst);
void free_all(t_list **lst, char *holder, t_list *last_node);
void clean_up_lst(t_list **lst);
void allocate_line(t_list *lst, char **line);
void extract_just_line(t_list *lst, char **line);
void ft_read_fd(t_list **lst, int *flag, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);

#endif