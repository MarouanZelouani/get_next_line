#include "get_next_line.h"

#include <unistd.h>
#include <fcntl.h>


int main ()
{
    int fd;
    char *line;

    fd = open("text.txt", O_RDONLY);
    line = get_next_line(fd);
    printf("%s", line);
}