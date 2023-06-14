#include <stdio.h>
#include <internal/io.h>

int puts(const char *s)
{
    for (; *s; s++)
    {
        if (write(1, s, 1) == -1)
            return EOF;
    }

    if (write(1, "\n", 1) == -1)
        return EOF;

    if (write(1, "\0", 1) == -1)
        return EOF;
    
    return 1;
}
