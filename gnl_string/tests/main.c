#include "get_next_line.h"

int main()
{
    int fd = open("text.txt", O_RDONLY);
    //int fd1 =  open("text1.txt", O_RDONLY);
    
    char *line = get_next_line(fd);
    printf("%s", line);
    char *line1 = get_next_line(fd);
    printf("%s", line1);
    char *line2 = get_next_line(fd);
    printf("%s", line2);

    free(line);
    free(line1);
    free(line2);
}