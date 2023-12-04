/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzelouan <mzelouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 13:39:16 by mzelouan          #+#    #+#             */
/*   Updated: 2023/12/04 05:10:16 by mzelouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS
#define GET_NEXT_LINE_BONUS

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif



typedef struct s_list
{
	char			*content;
	struct s_list	*next;
} t_list;

char *get_next_line(int fd);
void ft_read_fd(t_list **lst, int fd);
char *ft_extract_line_fd(t_list *lst);
void ft_clear_all_fd(t_list **lst);
void ft_add_to_lst(t_list **lst, char *holder, int read_cout);
int found_newline(t_list *lst);
t_list *ft_get_last_node(t_list *lst);
void ft_allocat_line(t_list *lst, char **line);
size_t	ft_strlen(const char *s);
void ft_free_list(t_list **lst, t_list *current, int op);

#endif