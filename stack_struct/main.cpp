#include <stdio.h>
#include <string.h>
#include "stack.h"
int main(int argc, char *argv[])
{
    STACK stack, new_stack;
    STACK *p = &stack, *p_new = &new_stack;
    int i = 1, s = 0, j = 0;
    while (i < argc)
    {
        if (strcmp(argv[i], "-S") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            initSTACK(p, s);
            printf("S  %d  ", p->max);
            continue;
        }
        else if (strcmp(argv[i], "-C") == 0)
        {
            initSTACK(p_new, *p);
            destroySTACK(p);
            initSTACK(p,*p_new);
            printf("C  ");
        }
        else if (strcmp(argv[i], "-I") == 0)
        {
            i++;
            while (i < argc && argv[i][0] >= '0' && argv[i][0] <= '9')
            {
                s = 0;
                for (j = 0; j < strlen(argv[i]); j++)
                    s = s * 10 + (argv[i][j] - '0');
                p = push(p, s);
                if (!p)
                {
                    printf("I  E");
                    return 0;
                }
                i++;
            }
            i--;
            printf("I  ");
        }
        else if (strcmp(argv[i], "-O") == 0)
        {
            int tmp;
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            for (j = 0; j < s; j++)
            {
                p = pop(p, tmp);
                if (!p)
                {
                    printf("O  E");
                    return 0;
                }
            }
            printf("O  ");
        }
        else if (strcmp(argv[i], "-A") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            initSTACK(p_new, s);
            p_new = assign(p_new, *p);
            destroySTACK(p);
            initSTACK(p,*p_new);
            printf("A  ");
        }
        else if (strcmp(argv[i], "-N") == 0)
        {
            printf("N  %d", p->pos);
            i++;
            continue;
        }
        else if (strcmp(argv[i], "-G") == 0)
        {
            i++;
            s = 0;
            for (j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            if (s > p->pos - 1)
            {
                printf("G  E");
                return 0;
            }
            printf("G  %d  ", p->elems[s]);
            i++;
            continue;
        }
        print(p);
        i++;
    }
    destroySTACK(p);
    destroySTACK(p_new);
    return 0;
}
