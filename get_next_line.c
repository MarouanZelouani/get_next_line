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
    line = extract_just_line(&lst);
    // clean up lst
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

char *extract_just_line(t_list **lst)
{
    t_list *node;

    node = lst;
    
}

int found_new_line(t_list *lst)
{
    t_list *node;

    if (lst == NULL)
        return (0);
    node = get_last_node(lst);
    if (ft_strchr(node->content, '\n') == NULL)
        return (0);
    return (1);
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

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
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

char	*ft_strdup(const char *s)
{
	size_t	slen;
	size_t	i;
	char	*p;

	i = 0;
	slen = ft_strlen(s);
	p = (char *)malloc((slen + 1) * sizeof(char));
	if (p == NULL)
		return (NULL);
	while (i < slen)
	{
		p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (ft_strdup(s1));
	if (!s1)
		return (ft_strdup(s2));
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = (char *)malloc(len * sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len);
	ft_strlcat(new, s2, len);
	return (new);
}
