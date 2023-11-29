#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#ifndef BUFFER_SUZE
#define BUFFER_SIZE 5
#endif


typedef struct s_list 
{
    char * content;
    struct s_list * next;
} t_list;

void ft_read_fd(t_list **lst, int fd);
char *ft_extract_line_fd(t_list *lst);
void ft_clear_all_fd(t_list **lst);
void ft_add_to_lst(t_list **lst, char *holder, int read_cout);
int found_newline(t_list *lst);
t_list *ft_get_last_node(t_list *lst);
void ft_allocat_line(t_list *lst, char **line);
//void ft_clear_list(t_list *lst);
size_t	ft_strlen(const char *s);

/*...................................................*/

char *get_next_line(int fd)
{
    static t_list *lst; 
    char *line;
    //char *holder;

    line = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, line, 0) == -1)
        return (NULL);
    //int eof = read(fd, holder, BUFFER_SIZE);
    //printf("%d\n", eof);
    // if (eof == 0)
    // {
    //     line = ft_extract_line_fd(lst);
    //     free(lst->content);
    //     free(lst);
    //     lst = NULL;
    //     return (line);
    // }
    ft_read_fd(&lst, fd);
    if (lst == NULL)
        return (NULL);
    line = ft_extract_line_fd(lst);
    ft_clear_all_fd(&lst);
    return (line);
}

void ft_read_fd(t_list **lst, int fd)
{
    char *holder;
    int read_count;
    char *line;

    line = NULL;
    holder = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (holder == NULL)
        return ;
    while (!found_newline(*lst))
    {
        read_count = read(fd, holder, BUFFER_SIZE);
        //printf("n\n%d\n", read_count);
        
        if (!read_count)
        {
            //printf("noooo\n");
            free(holder);
            char *line = ft_extract_line_fd(*lst);
            //printf("%s\n", line);
            free(line);
            t_list *tmp;
            while ((*lst) != NULL)
            {
                tmp = *lst;
                *lst = (*lst)->next;
                free(tmp->content);
                free(tmp);
            }
            // lst = NULL;
            return ;
        }
        holder[read_count] = '\0';
        //add fi lekhar dyal lst
        ft_add_to_lst(lst, holder, read_count);
    }
    //printf("%d\n", read_count);
    free(holder);
}

/*----------------------------------extraction--------------------------------------*/
char *ft_extract_line_fd(t_list *lst)
{
    char *line;
    int i;
    int j;

    // if (lst == NULL)
    // {
    //     printf("=====================\n");
    //     printf("null\n");
    //     printf("=====================\n");
    // }
    // else 
    // {
    //     printf("=====================\n");
    //     printf("%s\n", (lst)->content);
    //     printf("=====================\n");
    // }
    ft_allocat_line(lst, &line);
    if (line == NULL)
        return (NULL);
    j = 0;
    while (lst)
    {
        i = 0;
        while (lst->content[i] && lst->content[i] != '\n')
        {
            line[j] = lst->content[i];
            i++;
            j++;
        }
        if (lst->content[i] == '\n')
        {
            line[j] = '\n';
            j++;
        }
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
/*---------------------------------clean up-------------------------------*/

// void ft_clear_all_fd(t_list **lst)
// {
//     t_list *node;
//     t_list *new;
//     char *holder;
//     int i;
//     int j;

//     node = ft_get_last_node (*lst);
//     new = malloc(sizeof(t_list));
//     if (new == NULL)
//         return ;
//     new->content = malloc((BUFFER_SIZE + 1) * sizeof(char));
//     new->next = NULL;
//     if (new->content == NULL)
//         return ;
//     i = 0;
//     while (node->content[i] && node->content[i] != '\n')
//         i++;
//     if (node->content && node->content[i] == '\n')
//         i++;
//     j = 0;
//     while (node->content[i])
//     {
//         new->content[j] = node->content[i];
//         i++;
//         j++;
//     }
//     new->content[j] = '\0';
//     // printf("----\n");
//     // printf("%s", new->content);
//     // printf("-----\n");

//     // if (node)
//     // {
//     // }
//     //free(holder);
//     // printf("lst %p\n", lst);
//     // printf("*lst %p\n", *lst);
//     ft_clear_list(*lst);
//     *lst = new; 

//     // printf("=====================\n");
//     // printf("%s\n", new->content);
//     // printf("=====================\n");

    
//     //free(node->content);
//     // free(node);
//     // if (new->content[0])
//     //     *lst = new;
//     // else 
//     // {
//     //     free(new->content);
//     //     free(new);
//     // }


//     // while (lst != NULL)
// 	// {
// 	// 	next = *lst->next;
// 	// 	ft_lstdelone(node, del);
//     //     free(*lst-);
// 	// 	node = next;
// 	// }
// 	// *lst = NULL;
// }

void ft_clear_all_fd(t_list **lst)
{
    t_list  *current;
    t_list  *tmp;
    char    *holder;
    char    *new_content;
    int     i;
    int     len;

    tmp = NULL;
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
    {
        new_content[len] = holder[i];
        len++;
        i++;
    }
    new_content[len] = '\0';
    free(current->content);
    current->content = new_content;

    // printf("=====================\n");
    // printf("%s\n", current->content);
    // printf("=====================\n");

    while ((*lst) != current)
    {
        tmp = *lst;
        *lst = (*lst)->next;
        free(tmp->content);
        free(tmp);
    }
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

    if (!s)
        return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

// void ft_clear_list(t_list *lst)
// {
//     t_list	*current;
// 	t_list	*next;

// 	current = lst;
// 	while (current)
// 	{
// 		free(current->content);
// 		next = current->next;
// 		free(current);
// 		current = next;
// 	}
// }

/*------------------------------------------------------------------------*/

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

t_list *ft_get_last_node(t_list *lst)
{
    t_list	*node;

	node = NULL;
    if (lst == NULL)
        return (NULL);
	while (lst)
	{
		if (lst->next == NULL)
			node = lst;
		lst = lst->next;
	}
	return (node);
}

void ft_add_to_lst(t_list **lst, char *holder, int read_count)
{
    t_list *new;
    t_list *node;
    int i;

    i = 0;
    new = malloc(sizeof(t_list));
    if (new == NULL)
        return ;
    new->next = NULL;
    new->content = malloc ((read_count + 1) * sizeof(char));
    new->content[read_count] = '\0';
    if (new->content == NULL)
        return ;
    while (holder[i] && i < read_count)
    {
        new->content[i] = holder[i];
        i++;
    }
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

int main ()
{
    //t_list *head;
    // t_list *node;
    // t_list *node2;
    // t_list *node1;    //  head -> node1 -> node -> NULL

    //head = NULL;
    
    // node2 = malloc(sizeof(t_list));
    // char ttt[] = "marouanzelouan";
    // node2->content = ttt;
    // node2->next = NULL;

    // node = malloc(sizeof(t_list));
    // char t[] = "marouan\nzelouan";
    // node->content = t;
    // node->next = node2;

    // node1 = malloc(sizeof(t_list));
    // char tt[] = "marouanzelouan";
    // node1->content = tt;
    // node1->next = node;

    // head = node1;

    int fd = open("text.txt", O_RDONLY);
    // ft_read_fd(&head, fd);
    // char *line = ft_extract_line_fd(head);
    

    char *line = get_next_line(fd);
    printf("%s", line);
    free(line);

    char *line1 = get_next_line(fd);
    printf("%s", line1);
    free(line1);

    char *line2 = get_next_line(fd);
    printf("%s", line2);
    free(line2);

    char *line3 = get_next_line(fd);
    printf("%s", line3);
    free(line3);

    char *line4 = get_next_line(fd);
    printf("%s", line4);
    free(line4);


    char *line5 = get_next_line(fd);
    printf("%s", line5);
    free(line5);
    

    printf("--------------------------------------------\n");
    //clearing the list
    // ft_clear_all_fd(&head);
    // if (head != NULL)
    //     printf("%s\n", head->content);
    // char buf[10];
    // read(fd, buf, 5);
    // printf("%s\n", head->content);
    //printf("%s", ft_get_last_node(head)->content);
    //char *line;
    //ft_allocat_line(head, &line);
    // char tt[] = "marouanzelouan";
    // ft_add_to_lst(&head, tt, 14);

    // printf("%s", ft_get_last_node(head)->content);
}