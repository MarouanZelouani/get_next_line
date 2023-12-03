#include "get_next_line_bonus.h"

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
    
    printf("LINE 1 : ");
    char *line = get_next_line(fd);
    printf("%s", line);

    printf("LINE 2 : ");
    char *line1 = get_next_line(fd);
    printf("%s", line1);

    printf("LINE 3 : ");
    char *line2 = get_next_line(fd);
    printf("%s", line2);

    printf("LINE 4 : ");
    char *line3 = get_next_line(fd);
    printf("%s", line3);


    printf("LINE 5 : ");
    char *line4 = get_next_line(fd);
    printf("%s", line4);

    printf("LINE 6 : ");
    char *line5 = get_next_line(fd);
    printf("%s", line5);
    
    printf("LINE 7 : ");
    char *line6 = get_next_line(fd);
    printf("%s", line6);

    printf("LINE 8 : ");
    char *line7 = get_next_line(fd);
    printf("%s", line7);
    

    free(line);
    free(line1);
    free(line2);
    free(line3);
    free(line4);
    free(line5);
    free(line6);
    free(line7);
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