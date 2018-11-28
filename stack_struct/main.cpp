#include "stack_struct.h"

int main(int argc, char *argv[])
{
    STACK *p = new STACK;
    int i = 1;
    while (i < argc)
    {
        if (strcmp(argv[i], "-S") == 0)
        {
            i++;
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            initSTACK(p, s);
            printf("S  %d  ", p->max);
            continue;
        }
        else if (strcmp(argv[i], "-C") == 0)
        {
            STACK *q = new STACK;
            initSTACK(q, *p);
            destroySTACK(p);
            p = q;
            printf("C  ");
        }
        else if (strcmp(argv[i], "-I") == 0)
        {
            i++;
            while (i < argc && argv[i][0] >= '0' && argv[i][0] <= '9')
            {
                int s = 0;
                for (int j = 0; j < strlen(argv[i]); j++)
                    s = s * 10 + (argv[i][j] - '0');
                try
                {
                    p = push(p, s);
                    i++;
                }
                catch (...)
                {
                    printf("I  E");
                    destroySTACK(p);
                    return 1;
                }
            }
            i--;
            printf("I  ");
        }
        else if (strcmp(argv[i], "-O") == 0)
        {
            int tmp;
            i++;
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            for (int j = 0; j < s; j++)
            {
                try
                {
                    p = pop(p, tmp);
                }
                catch (...)
                {
                    printf("O  E");
                    destroySTACK(p);
                    return 1;
                }
            }
            printf("O  ");
        }
        else if (strcmp(argv[i], "-A") == 0)
        {
            i++;
            int s = 0;
            STACK *q = new STACK;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            initSTACK(q, s);
            q = assign(q, *p);
            destroySTACK(p);
            p = q;
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
            int s = 0;
            for (int j = 0; j < strlen(argv[i]); j++)
                s = s * 10 + (argv[i][j] - '0');
            try
            {
                printf("G  %d  ", getelem(p, s));
                i++;
            }
            catch (...)
            {
                printf("G  E");
                destroySTACK(p);
                return 1;
            }
            continue;
        }
        print(p);
        i++;
    }
    destroySTACK(p);
    return 0;
}
